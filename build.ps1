param(
    [ValidateSet('x64','ARM64')][string]$Architecture = 'x64',
    [string]$Generator
)
$ErrorActionPreference = 'Stop'
$buildDirectory = Join-Path $PSScriptRoot "build\$Architecture"
$arguments = @('-S', $PSScriptRoot, '-B', $buildDirectory, '-A', $Architecture)
if ($Generator) { $arguments += @('-G', $Generator) }
& cmake @arguments
if ($LASTEXITCODE -ne 0) { throw 'CMake configure failed.' }
& cmake --build $buildDirectory --config Release
if ($LASTEXITCODE -ne 0) { throw 'CMake build failed.' }
$package = Join-Path $PSScriptRoot "dist\$Architecture"
New-Item -ItemType Directory -Force $package | Out-Null
Copy-Item -LiteralPath (Join-Path $buildDirectory 'Release\winmm.dll') -Destination $package -Force
Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'LICENSE') -Destination $package -Force
Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'vendor\dotnet\LICENSE.txt') -Destination (Join-Path $package 'dotnet-LICENSE.txt') -Force
Get-FileHash -LiteralPath (Join-Path $package 'winmm.dll') -Algorithm SHA256
