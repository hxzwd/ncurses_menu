
#!/bin/bash

source ~/cecho.sh

#echo "In build.sh script"
#echo "Run make"

#( make && echo "Build!... Ok!..." ) || echo "Build!... Errors!..."

#echo "End"

cecho "In build.sh script" "green"
cecho -e "Run make\n" "green"

STATUS=""

cecho -e -n "Build!...\n" "green"

( make && STATUS="ok" ) || STATUS="fail"



if [[ $STATUS == "ok" ]]
then
	
	cecho -e "Build status =\nOk!..." "green"
	cecho "Finish successful" "green"
fi

if [[ $STATUS == "fail" ]]
then
	cecho -e "Build status =\nErrors!..." "red"
	cecho "Finish with errors" "red"
fi


