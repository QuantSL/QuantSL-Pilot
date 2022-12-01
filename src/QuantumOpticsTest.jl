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

