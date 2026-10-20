# PCL-CE Region Unlocker

A small `winmm.dll` extension for **PCL-CE (Plain Craft Launcher Community Edition)** that removes download region restrictions by making its region policy return `Other`.

## Usage

1. Close PCL-CE completely.
2. Place `winmm.dll` next to the PCL-CE executable, then launch it normally.

Use the DLL matching the **launcher process architecture**: x64 or ARM64.

## Build

```powershell
./build.ps1 -Architecture x64
./build.ps1 -Architecture ARM64
```

## Credits

Developed with assistance from **ChatGPT**. This is an independent project and is not affiliated with the PCL-CE team.

## License

MIT. Bundled .NET headers retain their license in `vendor/dotnet/LICENSE.txt`.
