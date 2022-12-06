# Example

The QSL file
```
parameter Ω_{Ryd}, Ω, U_{int}, N
subsystem Ryd

n_{Ryd} = σ⁺_[Ryd] * σ⁻_[Ryd]
H_{Ryd} = Ω_{Ryd} * σx_[Ryd]

H_{Rabi} = Ω * sum_[i]^N( σx_i )

n_i = σ⁺_i * σ⁻_i
H_{int}  = U_{int} * n_{Ryd} * sum_[i]^N( n_i )

H = H_{Ryd} + H_{Rabi} + H_{int}
```
describes a Rydberg atom that undergoes Rabi oscillations with frequency ``Ω_{Ryd}`` and a chain of ``N`` non-interacting atoms with Rabi frequency ``Ω``, together with a density-density interaction with strength ``U_{int}``.

The generated [QuantumOptics.jl](https://qojulia.org/) code will among other things provide the `generateSystem` function which generates a function or [QuantumOptics.jl](https://qojulia.org/) operator for each specified operator above:
```
parameters = Dict(
  :Ω_Ryd => 1.0,
  :Ω     => 0.1,
  :U_int => 3.0,
  :N => 4
)

operators = generateSystem(parameters = parameters)
```
Here `operators` provides easy access to all operators above, for example `operators.H` accesses the Hamiltonian or `operators.n(1)` is the excitation operator for the first atom in the chain.
Alternatively one can generate each element individually:
```
H_int = generate_H_int(parameters = parameters)
```
Notice the absence of curly brackets on the [Julia](https://julialang.org/) side.