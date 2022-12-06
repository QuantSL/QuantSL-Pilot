# Internal API

## \_generate\_indices\_from\_`SYMBOLE`

Samples the operator `SYMBOL` to find which indices appear within its definition.
Example:
```
_generate_indices_from_H(; parameters::Dict)
```
Samples all indices that appear in `H` and operators `H` depends upon.
`parameters` has to contain every parameter that was defined up to the definition of `H`.

## \_generate\_indices
Samples all indices in every operator occuring in the _qobj_ file.
```
_generate_indices(; parameters::Dict)
```
`parameters` has to contain every parameter specified in the _qobj_ file.

## \_generate\_`SYMBOLE`

General interface:
```
_generate_SYMBOLE(; basis, indexDict, operators, parameters::Dict)
```
`basis` denotes the composite basis for the total system, `indexDict` maps each `qobj` index onto an integer index (like `indexDict = Dict( (:α, 1) => 1 )` ), `operators` specify the definition of the elementary operators and `parameters` has to contain every parameter that was defined up to the definition of `SYMBOLE`.
See also [generate_`SYMBOLE`](@ref)