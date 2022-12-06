using Documenter

makedocs(
  sitename = "Quantum Optics Generator",
  # modules = [],
  # format = Documenter.HTML(assets = ["assets/favicon.ico"]),
  pages = [
    "index.md",
    "example.md",
    "API" => [
      "API/InternalAPI.md"
      "API/ExternalAPI.md"
    ]
  ]
)

deploydocs(
  repo = "github.com/QuantSL/QuantumOptics-Pilot",
)