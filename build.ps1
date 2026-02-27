



$PROGRAM_NAME="qt_calculator_gui"

$env:PATH += ";C:/DevFolder/tools/Frameworks/Qt/6.10.2/mingw_64/bin"

Write-Host "Cleaning and reconfiguring build..."
if (-not (Test-Path build)) {
    cmake -S . -B build -G "Ninja"
}

Write-Host "Building Program..."
cmake --build build

Write-Host "Build Successful! Attempting to run ${PROGRAM_NAME}.exe..."
& "./build/${PROGRAM_NAME}.exe"