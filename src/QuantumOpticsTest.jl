# using QuantumOptics

function _generate_indices(; parameters::Dict)
	results = ()
	return unique(results)
end

struct OperatorContainer
end

function generateSystem(; parameters::Dict)
	indices = _generate_indices(parameters = parameters)
	basis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )

	indexDict = Dict(key => val for (val, key) in enumerate(indices))

	operators = [f(SpinBasis(1//2)) for f in (sigmax, sigmay, sigmaz, sigmap, sigmam)]

	OperatorContainer(
	)
end

