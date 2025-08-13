param (
	[string]$Action=""
)

$source_file_c = "main.c"
$source_file_cpp "main.cpp"
$outputFile = "math_operations.exe"

function help_function {
	$script_name = $MyInvocation.MyCommand.Name
	$summary = @"
	usage: .\$script_name [ build_c | build_cpp | clean ]
"@
	Write-Host $summary
}

function build_app_c {
	gcc.exe -g3 -Wall $source_file_c -o $outputFile

	Write-Host "the libary has been built"
}

function build_app_cpp {
	g++.exe -g3 -Wall $source_file_cpp -o $outputFile

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
	"build_c" { build_app_c }
	"build_cpp" { build_app_cpp }
	"clean" { clean_up }
	default { help_function }
}