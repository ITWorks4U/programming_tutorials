# for Windows only
# use this powershell file to build or clean up your application
#
# It may happen, that your powershell script is unable to run on your
# system due security options. In that case try to type that command
# in the command line:
# Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass
# to bypass that limitation unless you're logged out

# use the additional argument as "action" to determine,
# which argument was given
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
	gcc.exe -g3 -Wall source\\linear_list.c source\\main.c -o linear_list.exe
	Write-Host "application has been built"
}

function clean_up {
	if (Test-Path "linear_list.exe") {
		Remove-Item "linear_list.exe"
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