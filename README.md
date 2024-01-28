# Trento Protontherapy Passive Line TOPAS Implementation and Microdosimetric Tissue Equivalent Proportional Counter

## References
- **Microdosimetry** Missiaggia, Marta, et al. "Investigation of in-field and out-of-field radiation quality with microdosimetry and its impact on relative biological effectiveness in proton therapy." International Journal of Radiation Oncology* Biology* Physics 115.5 (2023): 1269-1282.
- **Passive Beam Line** Tommasino, Francesco, et al. "A new facility for proton radiobiology at the Trento proton therapy centre: Design and implementation." Physica Medica 58 (2019): 99-106.

## Overview

This repository contains the TOPAS implementation of the Trento Protontherapy passive line and the microdosimetric implementation of a Tissue Equivalent Proportional Counter (TEPC). The code is designed for simulating and analyzing the behavior of proton therapy in the context of the Trento Protontherapy passive line and microdosimetric measurements using a TEPC.

## Features

- **TOPAS Implementation:** Simulate proton therapy using the TOPAS Monte Carlo simulation framework.
- **Microdosimetric TEPC:** Implement a Tissue Equivalent Proportional Counter for microdosimetric measurements.
- **Trento Protontherapy Passive Line:** Specific features related to the Trento Protontherapy passive line.

## Requirements

- [TOPAS](https://topas.ific.uv.es/) (Monte Carlo simulation software)

## Usage

1. Install TOPAS according to its documentation.
2. Clone this repository: `git clone https://github.com/your-username/your-repository.git`
3. Navigate to the project directory: `cd your-repository`
4. Compile the *"topas_extension"* folder according the topas documetation.
5. Execute the simulation: `topas example/PassiveScattering_SphericalTEPC.txt`

## Example
The example *example/PassiveScattering_SphericalTEPC.txt* simulates the passive scattering beamline which produces a SOBP. The geometry includes a water phantom where a TEPC is located. In the example the TEPC is located at 12 cm water depth from the entrance.
You can change the TEPC depth by modifyng the line: `d:Ge/AlShellOut/TransZ   = Ge/AlShellOut/TepcStartPos - <TEPC_DEPTH> mm`. If `<TEPC_DEPTH>` is equal to 0, it means that the TEPC is at the water phantom entrance.  

## Output

- Microdosimetri extension output

## License

This project is licensed under the [MIT License](LICENSE).

## Authors

- Giorgio Cartechini gxc1962@miami.edu and giorgio.cartechini@gmail.com
- Marta Missiaggia mxm194331@miami.edu
