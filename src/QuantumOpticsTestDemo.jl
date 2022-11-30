using QuantumOptics

struct QObj
  parameters

  H_int
  n_
  H
  H_test_
end

function _generate_n_(parameters::Dict, basis, embedDictionary)
  haskey(parameters, :N)
  haskey(parameters, :Ω)
  haskey(parameters, :J)
  haskey(parameters, :U_int)

  sz = sigmaz(SpinBasis(1//2))
  return (i::Int, j::Int) -> embed(basis, sz, embedDictionary(i)) * embed(basis, sz, embedDictionary(j))
end

# Idea: return indices from each "atomic expression" directly, otherwise traverse (potentially recursive!) expression
function _generate_indices_from_n_(parameters::Dict, i, j)
  results = i, j
  return results
end

function _generate_indices_from_H(parameters::Dict)
  results = ()
  for i ∈ 1:parameters[:N]
    for j ∈ 1:parameters[:N]
      results = (results..., _generate_indices_from_n_(parameters, i, j))
    end
  end
  return results
end

function generateQuantumObjects(parameters::Dict)
  haskey(parameters, N)
  haskey(parameters, Ω)
  haskey(parameters, J)
  haskey(parameters, U_int)
end