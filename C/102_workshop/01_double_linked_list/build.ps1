param (
	[string]$Action=""
)

function help_function {
	$script_name = $MyInvocation.MyCommand.Name
	$summary = @"
	usage: .\$script_name [build | clean]
"@
	Write-Host $summary
}

function build_app {
	gcc.exe -g3 -Wall source\\double_linked_list.c source\\main.c -o double_linked_list.exe
	Write-Host "application has been built"
}

function clean_up {
	if (Test-Path "double_linked_list.exe") {
		Remove-Item "double_linked_list.exe"
		Write-Host "application has been removed"
	} else {
		"application does not exist; nothing to do here..."
	}
}

# now determine which argument was given
switch ($Action.ToLower()) {
	"build" { build_app }
	"clean" { clean_up }
	default { help_function }
}