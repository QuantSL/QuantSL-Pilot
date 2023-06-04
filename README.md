# QuantSL

[![](https://img.shields.io/badge/docs-dev-blue.svg)](https://quantsl.github.io/QuantSL-Pilot/dev/)

*QuantSL* is a domain-specific language (DSL) that enables a natural description of diverse quantum systems.
The goals of this project encompass:
1. The potential to list and tabulate multiple quantum systems and link them by their shared properties, creating a searchable network of quantum materials and allowing scientists and quantum engineers to look up and compare different systems easily.
2. A universal and citeable database for Hamiltonians, similar to the [On-Line Encyclopedia of Integer Sequences (OEIS)](https://oeis.org/).
3. A simple and direct way of translating the natural definition of the quantum system into numerical code for multiple backends.

This repository is the proof of principle pilot project, demonstrating the baseline design choices for the *QuantSL* language and displaying the ease of accomplishing the third goal by being able to export to the two numerical backends [QuantumOptics.jl] and [ITensors.jl].

[QuantumOptics.jl]: https://qojulia.org/
[ITensors.jl]: https://github.com/ITensor/ITensors.jl
