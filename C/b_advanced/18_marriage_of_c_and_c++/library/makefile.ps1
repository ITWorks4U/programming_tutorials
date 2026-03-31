param (
	[string]$Action=""
)

$source_file_c = "math_operations.c"
$source_file_cpp = "math_operations.cpp"
$outputDll = "math_operations.dll"
$importLib = "math_operations.a"
$exportPath = "..\run_example\$outputDll"
$asm_c = "math_assembly_c.asm"
$asm_cpp = "math_assembly_cpp.asm"

function help_function {
	$script_name = $MyInvocation.MyCommand.Name
	$summary = @"
	usage: .\$script_name [build | build_assembly | clean]
"@
	Write-Host $summary
}

function build_app {
	$gccArgs = @("-g3", "-Wall", "-DMATH_OPERATIONS_EXPORTS", "-shared", "-o", $outputDll, $source_file_cpp, "-Wl,--out-implib=$importLib")
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

	if (Test-Path "$asm_c") {
		Remove-Item "$asm_c"
	}

	if (Test-Path "$asm_cpp") {
		Remove-Item "$asm_cpp"
	}
}

function build_assembly {
	Write-Host "creating assembly files instead..."
	$gccArgs = @("-g3", "-Wall", "-DLIBARY_MAKER_EXPORTS", "-S", $source_file_c, "-o", $asm_c)
	gcc.exe $gccArgs

	$gccArgs = @("-g3", "-Wall", "-DLIBARY_MAKER_EXPORTS", "-S", $source_file_cpp, "-o", $asm_cpp)
	gcc.exe $gccArgs
}

# now determine which argument was given
switch ($Action.ToLower()) {
	"build" { build_app }
	"clean" { clean_up }
	"build_assembly" { build_assembly }
	default { help_function }
}