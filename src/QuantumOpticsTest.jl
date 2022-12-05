# using QuantumOptics

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

function _generate_indices_from_H_onsite(; parameters::Dict)
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

function _generate_indices_from_H_int(; parameters::Dict)
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
	results = results..., ( _generate_indices_from_H_onsite(; parameters = parameters) )...
	results = results..., ( _generate_indices_from_H_int(; parameters = parameters) )...
	results = results..., ( _generate_indices_from_H_lattice(; parameters = parameters) )...
	return results
end

function _generate_indices(; parameters::Dict)
	results = ()
	results = results..., (_generate_indices_from_H_onsite(parameters = parameters)...)
	results = results..., (_generate_indices_from_H_int(parameters = parameters)...)
	results = results..., (_generate_indices_from_H_lattice(parameters = parameters)...)
	results = results..., (_generate_indices_from_H(parameters = parameters)...)
	return unique(results)
end

function generate_n_test(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	basis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )

	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	σx, σy, σz, σp, σm = [f(SpinBasis(1//2)) for f in (sigmax, sigmay, sigmaz, sigmap, sigmam)]

	return (i) -> embed(basis, indexDict[(:a, i)], σx) * embed(basis, indexDict[(:b, i)], σx)
end

function generate_n(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	basis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )

	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	σx, σy, σz, σp, σm = [f(SpinBasis(1//2)) for f in (sigmax, sigmay, sigmaz, sigmap, sigmam)]

	return (i, j) -> embed(basis, indexDict[i], σz) * embed(basis, indexDict[j], σz)
end

function generate_H_onsite(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	basis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )

	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	σx, σy, σz, σp, σm = [f(SpinBasis(1//2)) for f in (sigmax, sigmay, sigmaz, sigmap, sigmam)]

	return parameters[:U_int] * sum(i -> 
		sum(j -> 
			_generate_n(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)(i, j), [1:parameters[:N];]
		), [1:parameters[:N];]
	)
end

function generate_H_int(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	basis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )

	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	σx, σy, σz, σp, σm = [f(SpinBasis(1//2)) for f in (sigmax, sigmay, sigmaz, sigmap, sigmam)]

	return parameters[:J] * sum(i -> 
		sum(j -> 
			embed(basis, indexDict[i], σx) * embed(basis, indexDict[j], σx), [1:parameters[:N];]
		), [1:parameters[:N];]
	)
end

function generate_H_lattice(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	basis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )

	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	σx, σy, σz, σp, σm = [f(SpinBasis(1//2)) for f in (sigmax, sigmay, sigmaz, sigmap, sigmam)]

	return sum(i -> 
		_generate_n_test(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)(i) * _generate_n_test(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)(i) * embed(basis, indexDict[i], σz), [1:parameters[:N];]
	)
end

function generate_H(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	basis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )

	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	σx, σy, σz, σp, σm = [f(SpinBasis(1//2)) for f in (sigmax, sigmay, sigmaz, sigmap, sigmam)]

	return _generate_H_onsite(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)() + _generate_H_int(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)() + _generate_H_lattice(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)()
end

function _generate_n_test(; basis, indexDict, operators, parameters::Dict)
	σx, σy, σz, σp, σm = operators

	return (i) -> embed(basis, indexDict[(:a, i)], σx) * embed(basis, indexDict[(:b, i)], σx)
end

function _generate_n(; basis, indexDict, operators, parameters::Dict)
	σx, σy, σz, σp, σm = operators

	return (i, j) -> embed(basis, indexDict[i], σz) * embed(basis, indexDict[j], σz)
end

function _generate_H_onsite(; basis, indexDict, operators, parameters::Dict)
	σx, σy, σz, σp, σm = operators

	return parameters[:U_int] * sum(i -> 
		sum(j -> 
			_generate_n(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)(i, j), [1:parameters[:N];]
		), [1:parameters[:N];]
	)
end

function _generate_H_int(; basis, indexDict, operators, parameters::Dict)
	σx, σy, σz, σp, σm = operators

	return parameters[:J] * sum(i -> 
		sum(j -> 
			embed(basis, indexDict[i], σx) * embed(basis, indexDict[j], σx), [1:parameters[:N];]
		), [1:parameters[:N];]
	)
end

function _generate_H_lattice(; basis, indexDict, operators, parameters::Dict)
	σx, σy, σz, σp, σm = operators

	return sum(i -> 
		_generate_n_test(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)(i) * _generate_n_test(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)(i) * embed(basis, indexDict[i], σz), [1:parameters[:N];]
	)
end

function _generate_H(; basis, indexDict, operators, parameters::Dict)
	σx, σy, σz, σp, σm = operators

	return _generate_H_onsite(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)() + _generate_H_int(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)() + _generate_H_lattice(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)()
end

struct OperatorContainer
	n_test
	n
	H_onsite
	H_int
	H_lattice
	H
end

function generateSystem(; parameters::Dict)
	for parameter in [:N, :J, :U_int] # Check if all parameters are defined
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	indices = _generate_indices(parameters = parameters)
	basis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )

	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	operators = [f(SpinBasis(1//2)) for f in (sigmax, sigmay, sigmaz, sigmap, sigmam)]

	OperatorContainer(
		_generate_n_test(basis = basis, indexDict = indexDict, operators = operators, parameters = parameters), 
		_generate_n(basis = basis, indexDict = indexDict, operators = operators, parameters = parameters), 
		_generate_H_onsite(basis = basis, indexDict = indexDict, operators = operators, parameters = parameters), 
		_generate_H_int(basis = basis, indexDict = indexDict, operators = operators, parameters = parameters), 
		_generate_H_lattice(basis = basis, indexDict = indexDict, operators = operators, parameters = parameters), 
		_generate_H(basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)
	)
end

