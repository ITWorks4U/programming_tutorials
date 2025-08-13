#	this makefile is required to link the main
#	with the created library
#
#	to build the library, take a look in library_maker folder

param (
	[string]$Action=""
)

$sourceFile = "main.c"
$outputFile = "library_maker.exe"

function help_function {
	$script_name = $MyInvocation.MyCommand.Name
	$summary = @"
	usage: .\$script_name [build | clean]
"@
	Write-Host $summary
}

function build_app {
	# $gccArgs = @("-Wall", "-DLIBARY_MAKER_EXPORTS", "-shared", "-o", $outputDll, $sourceFile, "-Wl,--out-implib=$importLib")
	# gcc.exe $gccArgs
	# Remove-Item "$importLib"
	# Move-Item $outputDll "..\run_example"
	gcc.exe -g3 -Wall $sourceFile -o $outputFile

	Write-Host "the libary has been built"
}

function clean_up {
	if (Test-Path "$outputFile") {
		Remove-Item "$outputFile"
		Write-Host "the application has been removed"
	} else {
		"the application does not exist; nothing to do here..."
	}
}

# now determine which argument was given
switch ($Action.ToLower()) {
	"build" { build_app }
	"clean" { clean_up }
	default { help_function }
}