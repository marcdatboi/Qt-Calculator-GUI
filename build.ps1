



$PROGRAM_NAME="qt_calculator_gui"

Write-Host "Building Program..."
Set-Location .
cmake --build build ; if ($?) { & "./build/${PROGRAM_NAME}.exe" }

