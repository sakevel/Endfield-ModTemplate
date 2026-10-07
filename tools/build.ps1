$ErrorActionPreference='Stop'
$root=Split-Path $PSScriptRoot -Parent
cmake -S $root -B (Join-Path $root 'build') -G 'Visual Studio 17 2022' -A x64
if($LASTEXITCODE -ne 0){throw 'Configure failed'}
cmake --build (Join-Path $root 'build') --config Release --parallel 6
if($LASTEXITCODE -ne 0){throw 'Build failed'}
