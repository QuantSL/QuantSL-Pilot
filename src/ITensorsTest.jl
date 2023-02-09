using ITensors

function _generate_indices_from_n_test(i; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	results = ()
	results = results..., (:a, i)
	results = results..., (:b, i)
	return results
end

function _generate_indices_from_n(i, j; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

		results = ()
		results = results..., (i)
		results = results..., (j)
	return results
end

function _generate_indices_from_H_int(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	results = ()
	for i in [1:parameters[:N];]
		for j in [1:parameters[:N];]
			results = results..., ( _generate_indices_from_n(i, j; parameters = parameters) )...
		end
	end
	return results
end

function _generate_indices_from_H_hopping(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	results = ()
	for i in [1:parameters[:N];]
		for j in [1:parameters[:N];]
			results = results..., (i)
			results = results..., (j)
		end
	end
	return results
end

function _generate_indices_from_H_lattice(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	results = ()
	for i in [1:parameters[:N];]
		results = results..., ( _generate_indices_from_n_test(i; parameters = parameters) )...
		results = results..., ( _generate_indices_from_n_test(i; parameters = parameters) )...
		results = results..., (i)
	end
	return results
end

function _generate_indices_from_H(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	results = ()
	results = results..., ( _generate_indices_from_H_int(; parameters = parameters) )...
	results = results..., ( _generate_indices_from_H_hopping(; parameters = parameters) )...
	results = results..., ( _generate_indices_from_H_lattice(; parameters = parameters) )...
	return results
end

function _generate_indices(; parameters::Dict)
	results = ()
	results = results..., (_generate_indices_from_H_int(parameters = parameters)...)
	results = results..., (_generate_indices_from_H_hopping(parameters = parameters)...)
	results = results..., (_generate_indices_from_H_lattice(parameters = parameters)...)
	results = results..., (_generate_indices_from_H(parameters = parameters)...)
	return unique(results)
end

function generate_n_test(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	os1(i) = OpSum() + Op("Sx", indexDict[(:a, i)]) * Op("Sx", indexDict[(:b, i)])
	return (i) -> OpSum() + os1(i)
end

function generate_n(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	os1(i, j) = OpSum() + Op("Sz", indexDict[i]) * Op("Sz", indexDict[j])
	return (i, j) -> OpSum() + os1(i, j)
end

function generate_H_int(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	n = _generate_n(; indexDict = indexDict, parameters = parameters)

	os2_1(i, j) = OpSum() + n(i, j)
	os1 = OpSum() + parameters[:U_int]
	os2 = OpSum() + sum(i -> 
		sum(j -> 
			os2_1(i, j), [1:parameters[:N];]
		), [1:parameters[:N];]
	)
	return OpSum() + os1 * os2
end

function generate_H_hopping(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	os2_1_1(i, j) = OpSum() + Op("Sx", indexDict[i]) * Op("Sx", indexDict[j])
	os2_1(i) = OpSum() + sum(j -> 
		os2_1_1(i, j), [1:parameters[:N];]
	)
	os1 = OpSum() + parameters[:J]
	os2 = OpSum() + sum(i -> 
		os2_1(i), [1:parameters[:N];]
	)
	return OpSum() + os1 * os2
end

function generate_H_lattice(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	n_test = _generate_n_test(; indexDict = indexDict, parameters = parameters)

	os1_1(i) = OpSum() + n_test(i) * n_test(i) * Op("Sz", indexDict[i])
	os1 = OpSum() + sum(i -> 
		os1_1(i), [1:parameters[:N];]
	)
	return OpSum() + os1
end

function generate_H(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	H_int = _generate_H_int(; indexDict = indexDict, parameters = parameters)
	H_hopping = _generate_H_hopping(; indexDict = indexDict, parameters = parameters)
	H_lattice = _generate_H_lattice(; indexDict = indexDict, parameters = parameters)

	os1 = OpSum() + H_int + H_hopping + H_lattice
	return OpSum() + os1
end

function _generate_n_test(; indexDict, parameters::Dict)
	os1(i) = OpSum() + Op("Sx", indexDict[(:a, i)]) * Op("Sx", indexDict[(:b, i)])
	return (i) -> OpSum() + os1(i)
end

function _generate_n(; indexDict, parameters::Dict)
	os1(i, j) = OpSum() + Op("Sz", indexDict[i]) * Op("Sz", indexDict[j])
	return (i, j) -> OpSum() + os1(i, j)
end

function _generate_H_int(; indexDict, parameters::Dict)
	n = _generate_n(; indexDict = indexDict, parameters = parameters)

	os2_1(i, j) = OpSum() + n(i, j)
	os1 = OpSum() + parameters[:U_int]
	os2 = OpSum() + sum(i -> 
		sum(j -> 
			os2_1(i, j), [1:parameters[:N];]
		), [1:parameters[:N];]
	)
	return OpSum() + os1 * os2
end

function _generate_H_hopping(; indexDict, parameters::Dict)
	os2_1_1(i, j) = OpSum() + Op("Sx", indexDict[i]) * Op("Sx", indexDict[j])
	os2_1(i) = OpSum() + sum(j -> 
		os2_1_1(i, j), [1:parameters[:N];]
	)
	os1 = OpSum() + parameters[:J]
	os2 = OpSum() + sum(i -> 
		os2_1(i), [1:parameters[:N];]
	)
	return OpSum() + os1 * os2
end

function _generate_H_lattice(; indexDict, parameters::Dict)
	n_test = _generate_n_test(; indexDict = indexDict, parameters = parameters)

	os1_1(i) = OpSum() + n_test(i) * n_test(i) * Op("Sz", indexDict[i])
	os1 = OpSum() + sum(i -> 
		os1_1(i), [1:parameters[:N];]
	)
	return OpSum() + os1
end

function _generate_H(; indexDict, parameters::Dict)
	H_int = _generate_H_int(; indexDict = indexDict, parameters = parameters)
	H_hopping = _generate_H_hopping(; indexDict = indexDict, parameters = parameters)
	H_lattice = _generate_H_lattice(; indexDict = indexDict, parameters = parameters)

	os1 = OpSum() + H_int + H_hopping + H_lattice
	return OpSum() + os1
end

struct OperatorContainer
	n_test
	n
	H_int
	H_hopping
	H_lattice
	H
end

function generateSystem(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	OperatorContainer(
		_generate_n_test(indexDict = indexDict, parameters = parameters), 
		_generate_n(indexDict = indexDict, parameters = parameters), 
		_generate_H_int(indexDict = indexDict, parameters = parameters), 
		_generate_H_hopping(indexDict = indexDict, parameters = parameters), 
		_generate_H_lattice(indexDict = indexDict, parameters = parameters), 
		_generate_H(indexDict = indexDict, parameters = parameters)
	)
end

