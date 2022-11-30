# using QuantumOptics

function _generate_indices_from_n_test(i; parameters::Dict)
	for parameter in [:N, :Ω, :J, :U_int]
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	results = ()
	results = results..., (i)...

	return results
end

function _generate_indices_from_n(i, j; parameters::Dict)
	for parameter in [:N, :Ω, :J, :U_int]
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	results = ()
	results = results..., (i)...
	results = results..., (j)...

	return results
end

function _generate_indices_from_H(; parameters::Dict)
	for parameter in [:N, :Ω, :J, :U_int]
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	results = ()

	for i in [1:parameters[:N];]
		for j in [1:parameters[:N];]
			results = results..., (_generate_indices_from_n(i, j, parameters = parameters))...
		end
	end
	return results
end

function _generate_indices_from_H_alt(; parameters::Dict)
	for parameter in [:N, :Ω, :J, :U_int]
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	results = ()

	for i in [1:parameters[:N];]
		for j in [1:parameters[:N];]
			results = results..., (_generate_indices_from_n(i, j, parameters = parameters))...
		end
	end
	return results
end

function _generate_indices_from_H_test(i; parameters::Dict)
	for parameter in [:N, :Ω, :J, :U_int]
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	results = ()

	for j in [1:parameters[:N];]
		results = results..., (_generate_indices_from_n_test(i, parameters = parameters))...
		results = results..., (_generate_indices_from_n_test(j, parameters = parameters))...
	end
	return results
end

function _generate_indices(; parameters::Dict)
	for parameter in [:N, :Ω, :J, :U_int]
		!haskey(parameters, parameter) && error("Parameter $parameter not defined")
	end

	results = ()
	results = results..., (_generate_indices_from_H(parameters = parameters))...
	results = results..., (_generate_indices_from_H_alt(parameters = parameters))...
	return unique(results)
end

