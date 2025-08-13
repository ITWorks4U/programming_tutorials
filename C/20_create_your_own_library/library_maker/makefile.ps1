#	building the libary by using a powershell script
#	if this script does not work on your machine, then try to run
#	the batch file instead
#
#	if this also fails, then you must enter the compile commands into the command line instead
param (
	[string]$Action=""
)

$sourceFile = "libary_maker.c"
$outputDll = "libary_maker.dll"
$importLib = "liblibary_maker.a"
$exportPath = "..\run_example\$outputDll"

function help_function {
	$script_name = $MyInvocation.MyCommand.Name
	$summary = @"
	usage: .\$script_name [build | clean]
"@
	Write-Host $summary
}

function build_app {
	$gccArgs = @("-Wall", "-DLIBARY_MAKER_EXPORTS", "-shared", "-o", $outputDll, $sourceFile, "-Wl,--out-implib=$importLib")
	gcc.exe $gccArgs
	Remove-Item "$importLib"
	Move-Item $outputDll "..\run_example"

	Write-Host "the libary has been built"
}

function clean_up {
	if (Test-Path "$exportPath") {
		Remove-Item "$exportPath"
		Write-Host "the libary has been removed"
	} else {
		"the libary does not exist; nothing to do here..."
	}
}

# now determine which argument was given
switch ($Action.ToLower()) {
	"build" { build_app }
	"clean" { clean_up }
	default { help_function }
}