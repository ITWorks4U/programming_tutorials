#---------
# Create and play the game "Yahtzee!" in shell. "Roll" 6 dices and get the highest possible amount of
# points depending on given sub goals, like: "Highest number", "Full House", "Yahtzee!", ...
#
# author:	ITWorks4U
# created:	between September / October 2019
# updated:	August 5th, 2025
#---------

#---------
# definitions
#---------
# a state for each sub tuple => while the current sub goal is still available, $ALIVE is set to 1, otherwise 0
readonly ALIVE=1

# same as above
readonly CLOSED=0

readonly THREE_OF_A_KIND="ThreeOfAKind"
readonly FOUR_OF_A_KIND="FourOfAKind"
readonly SMALL_STRAIGHT="SmallStraight"
readonly LARGE_STRAIGHT="LargeStraight"

# holds the values of dices in order
readonly fixedDiceArray=(1 2 3 4 5 6)

readonly AUTHOR="ITWorks4U"
readonly VERSION="1.0.0.0"

# our dices
dices=(-1 -1 -1 -1 -1 -1)

# a mark which dice has already been checked
locked=(0 0 0 0 0 0)

# count all gotten points
points=0

# for each tuple section
markForSubWins=($ALIVE $ALIVE $ALIVE $ALIVE $ALIVE $ALIVE $ALIVE $ALIVE $ALIVE $ALIVE $ALIVE $ALIVE $ALIVE)

tuplesNames=("Aces" "Twos" "Threes" "Fours" "Fives" "Sixes" "Three_Of_a_Kind" "Four_Of_a_Kind" "Full_House" "Small_Straight" "Large_Straight" "Yahtzee" "Chance")

# there're 13 taks to do (0, 1, ..., 12)
nbrOfRounds=0

# the player may shuffle the dices up to three times in a row
ctrOfShuffles=0

#---------
# functions
#---------
function onSingleEyes() {
	currentPoints=0

	case $1 in
		1)
			if [ ${markForSubWins[0]} == $ALIVE ]; then
				markForSubWins[0]=$CLOSED

				for i in ${dices[*]}; do
					if [ $i -eq 1 ]; then
						currentPoints=`expr $currentPoints + 1`
					fi
				done
			fi
		;;
		2)
			if [ ${markForSubWins[1]} == $ALIVE ]; then
				markForSubWins[1]=$CLOSED

				for i in ${dices[*]}; do
					if [ $i == 2 ]; then
						currentPoints=`expr $currentPoints + 2`
					fi
				done
			fi
		;;
		3)
			if [ ${markForSubWins[2]} == $ALIVE ]; then
				markForSubWins[2]=$CLOSED

				for i in ${dices[*]}; do
					if [ $i == 3 ]; then
						currentPoints=`expr $currentPoints + 3`
					fi
				done
			fi
		;;
		4)
			if [ ${markForSubWins[3]} == $ALIVE ]; then
				markForSubWins[3]=$CLOSED

				for i in ${dices[*]}; do
					if [ $i == 4 ]; then
						currentPoints=`expr $currentPoints + 4`
					fi
				done
			fi
		;;
		5)
			if [ ${markForSubWins[4]} == $ALIVE ]; then
				markForSubWins[4]=$CLOSED

				for i in ${dices[*]}; do
					if [ $i == 5 ]; then
						currentPoints=`expr $currentPoints + 5`
					fi
				done
			fi
		;;
		6)
			if [ ${markForSubWins[5]} == $ALIVE ]; then
				markForSubWins[5]=$CLOSED

				for i in ${dices[*]}; do
					if [ $i == 6 ]; then
						currentPoints=`expr $currentPoints + 6`
					fi
				done
			fi
		;;
	esac

	return $currentPoints
}

function onOfAKind_N() {
	currentPoints=0
	ctr=0
	tmpVal=0

	# the dominant value for our six dices
	diceNumberToUse=0

	# determine how often a dice exists
	howOften=(0 0 0 0 0 0)

	if [ "$1" == $THREE_OF_A_KIND ]; then
		if [ ${markForSubWins[6]} == $ALIVE ]; then
			markForSubWins[6]=$CLOSED
	
			# may hold up to two three dices with the same
			doubles=(0 0)

	        for i in ${dices[*]}; do
	            case $i in
	                1)
						# for each 1
	                    howOften[0]=$((howOften[0] + 1));;
	                2)
						# for each 2
                        howOften[1]=$((howOften[1] + 1));;
	                3)
        	            howOften[2]=$((howOften[2] + 1));;
	                4)
	                    howOften[3]=$((howOften[3] + 1));;
	                5)
	                    howOften[4]=$((howOften[4] + 1));;
	                6)
	                    howOften[5]=$((howOften[5] + 1));;
                esac
            done

			# now determine how often a dice exists
            for ((j=0; j < 6; j++)); do
				# hold the current number
                tmpVal=${howOften[j]}

				# number of dice j exists three times
                if [ $tmpVal -eq 3 ]; then

					# check, if doubles[0] has not been set before
                    if [ ${doubles[0]} -eq 0 ]; then
						# then copy dice number j to doubles[0]
                        doubles[0]=${fixedDiceArray[$j]}
					# otherwise check, if doubles[1] has not been set before
                    elif [ ${doubles[1]} -eq 0 ]; then
						# then copy dice number j to doubles[1]
                        doubles[1]=${fixedDiceArray[$j]}
                    fi
                fi
            done

            #echo " howOften: ${howOften[*]}"
            #echo " doubles: ${doubles[*]}"

			# there are no three dices with the same value
	        if [[ ${doubles[0]} -eq 0 && ${doubles[1]} -eq 0 ]]; then
				# so leave the function earlier
	            return 0

			# otherwise a single tri-tuple of dices exists
            elif [[ ${doubles[0]} -ne 0 && ${doubles[1]} -eq 0 ]]; then
				# the dominant dice number to use
                diceNumberToUse=${doubles[0]}
			# or two tri-tuples exists
            else
				# check, which one has a higher value
                if [ ${doubles[0]} -lt ${doubles[1]} ]; then
                    diceNumberToUse=${doubles[1]}
                else
                    diceNumberToUse=${doubles[0]}
                fi
            fi

            for i in ${dices[*]}; do
				# take dice i and compare with the dominant value
                if [ $i -eq $diceNumberToUse ]; then
                    currentPoints=$(($currentPoints + $i))
                    ctr=$(($ctr + 1))
                fi
            done

            if [ $ctr -eq 3 ]; then
                return $currentPoints
            fi
        fi
	elif [ "$1" == $FOUR_OF_A_KIND ]; then
	    if [ ${markForSubWins[7]} == $ALIVE ]; then
	        markForSubWins[7]=$CLOSED
	
            for i in ${dices[*]}; do
	            case $i in
	                1)
	                    howOften[0]=$((howOften[0] + 1));;
	                2)
                        howOften[1]=$((howOften[1] + 1));;
	                3)
        	            howOften[2]=$((howOften[2] + 1));;
	                4)
	                    howOften[3]=$((howOften[3] + 1));;
	                5)
	                    howOften[4]=$((howOften[4] + 1));;
	                6)
	                    howOften[5]=$((howOften[5] + 1));;
                esac
            done

            #echo " howOften: ${howOften[*]}"

			# count the number of tries
            nbrOfTries=0

	        for ((i=0; i < 6; i++)); do
	            tmpVal=${howOften[i]}
	        
	            if [ $tmpVal -eq 4 ]; then
	                diceNumberToUse=${fixedDiceArray[$i]}
	                break
                else
                    nbrOfTries=$(($nbrOfTries + 1))
	            fi
	        done

			# if the number of tries is 6, then there is no number
	        if [ $nbrOfTries -eq 6 ]; then
				# which exists exactly four times, thus FOUR_OF_A_KIND returns 0
	            return 0
	        fi

			# finally, use every dice
	        for i in ${dices[*]}; do
				# and check, if its value is equal to the dominant number
	            if [ $diceNumberToUse -eq $i ]; then
                    currentPoints=$(($currentPoints + $i))
                    ctr=$(($ctr + 1))
	            fi
	        done

		    if [ $ctr -eq 4 ]; then
			    return $currentPoints
		    fi
        fi
	fi

	return 0
}

function onFullHouse() {
	# holds the amount of all dices
    diceHolder=(0 0 0 0 0 0)

	# holds a full house in binary form, where:
	# {0,0} or {1,0} or {0,1} := no full house
	# {1,1} := full house
    fullHouseHolder=(0 0)

    if [ ${markForSubWins[8]} == $ALIVE ]; then
        markForSubWins[8]=$CLOSED

        for i in ${dices[*]}; do
            case $i in
                1)
                    diceHolder[0]=$((diceHolder[0] + 1));;
                2)
                    diceHolder[1]=$((diceHolder[1] + 1));;
                3)
                    diceHolder[2]=$((diceHolder[2] + 1));;
                4)
                    diceHolder[3]=$((diceHolder[3] + 1));;
                5)
                    diceHolder[4]=$((diceHolder[4] + 1));;
                6)
                    diceHolder[5]=$((diceHolder[5] + 1));;
            esac
        done

        for i in ${diceHolder[*]}; do
            if [ $i -eq 3 ]; then
                fullHouseHolder[0]=1
            elif [ $i -eq 2 ]; then
                fullHouseHolder[1]=1
            fi
        done

        if [[ ${fullHouseHolder[0]} -eq 1 && ${fullHouseHolder[1]} -eq 1 ]]; then
            return 25
        fi
    fi

	return 0
}

function onStraight() {
    diceHolder=(0 0 0 0 0 0)

    for i in ${dices[*]}; do
        case $i in
            1)
                diceHolder[0]=$((diceHolder[0] + 1));;
            2)
                diceHolder[1]=$((diceHolder[1] + 1));;
            3)
                diceHolder[2]=$((diceHolder[2] + 1));;
            4)
                diceHolder[3]=$((diceHolder[3] + 1));;
            5)
                diceHolder[4]=$((diceHolder[4] + 1));;
            6)
                diceHolder[5]=$((diceHolder[5] + 1));;
        esac
    done

	# {3,4} are required for a small/large straight, means:
	# if one of these both numbers doesn't exist, then there
	 # is no chance to get a small/large straight anyway
    if [[ ${diceHolder[2]} -eq 0 || ${diceHolder[3]} -eq 0 ]]; then
        return 0
    fi

	# will hold "SMALL_STRAIGHT" or "LARGE_STRAIGHT"
    choosenOption=$1
	# start with 0 to count up to four
    counter=0

	# will hold the lower bound
    lowerLimit=0

	# will hold the upper bound for a small straight
    upperLimit=0

	# check for a small straight
    if [ "$choosenOption" == $SMALL_STRAIGHT ]; then
        if [ ${markForSubWins[9]} == $ALIVE ]; then
            markForSubWins[9]=$CLOSED

			# start with the first number (1)
            startNumber=${diceHolder[0]}

			# just check, if there's no number 1
            if [ $startNumber -eq 0 ]; then
				# then start with number 2
                startNumber=${diceHolder[1]}

				# if there's also no number 2, then use number 3 as last count
                if [ $startNumber -eq 0 ]; then
                    startNumber=${diceHolder[2]}

                    lowerLimit=2
                    upperLimit=6
                else
                    lowerLimit=1
                    upperLimit=5
                fi

			# only if, a small straight {X,Y,3,4,5,6} appears, where
            elif [[ $startNumber -ne 0 && ${diceHolder[1]} -eq 0 ]] ; then
				# X,Y are 1 or 3 or 4 or 5 or 6, but there's no 2
                lowerLimit=2
                upperLimit=6
            else
                lowerLimit=0
                upperLimit=4
            fi

			# for combination {1,2,3,4} or {2,3,4,5} or {3,4,5,6}
            for ((i=$lowerLimit; i < $upperLimit; i++)); do
                if [ ${diceHolder[$i]} -ne 0 ]; then
                    counter=$(($counter + 1))
                fi
            done

            if [ $counter -eq 4 ]; then
                return 30
            fi
        fi

	# check for large straight instead
	elif [ "$choosenOption" == $LARGE_STRAIGHT ]; then
	    if [ ${markForSubWins[10]} == $ALIVE ]; then
	        markForSubWins[10]=$CLOSED
	
			# start with the first number (1)
            startNumber=${diceHolder[0]}

			# just check, if there's no number 1
            if [ $startNumber -eq 0 ]; then
				# then start with number 2
                startNumber=${diceHolder[1]}

                lowerLimit=1
                upperLimit=6
            else
                lowerLimit=0
                upperLimit=5
            fi

			# for combination {1,2,3,4,5} or {2,3,4,5,6}
            for ((i=$lowerLimit; i < $upperLimit; i++)); do
                if [ ${diceHolder[$i]} -ne 0 ]; then
                    counter=$(($counter + 1))
                fi
            done

            if [ $counter -eq 5 ]; then
                return 40
            fi
        fi
	fi

	return 0
}

function onYahtzee() {
    diceHolder=(0 0 0 0 0 0)

    if [ ${markForSubWins[11]} == $ALIVE ]; then
        markForSubWins[11]=$CLOSED

        for i in ${dices[*]}; do
            case $i in
                1)
                    diceHolder[0]=$((diceHolder[0] + 1));;
                2)
                    diceHolder[1]=$((diceHolder[1] + 1));;
                3)
                    diceHolder[2]=$((diceHolder[2] + 1));;
                4)
                    diceHolder[3]=$((diceHolder[3] + 1));;
                5)
                    diceHolder[4]=$((diceHolder[4] + 1));;
                6)
                    diceHolder[5]=$((diceHolder[5] + 1));;
            esac
        done

        for i in ${diceHolder[*]}; do
            if [ $i -eq 6 ]; then
                return 50
            fi
        done
    fi

	return 0
}

function onChance() {
    currentPoints=0

    if [ ${markForSubWins[12]} == $ALIVE ]; then
        markForSubWins[12]=$CLOSED
        
        for i in ${dices[*]}; do
            currentPoints=`expr $currentPoints + $i`
        done
    fi

	return $currentPoints
}

function shuffleDices() {
    for ((i=0; i < 6; i++)); do
		#	get a random number between [1,6]
        dices[i]=`expr $RANDOM % 6 + 1`
    done
}

function printCurrentDices() {
	echo -e "\n round `expr $nbrOfRounds + 1`: current shuffled dices: {${dices[*]}}"
}

function convertInput() {
	#	original dices
	#echo " #1: ${dices[*]}"

	read -p " Select which dice shall be shuffled again: " word

	for ((i = 1; i < 7; i++)); do
		#	get the character from position 1 to 6
		sign=`expr substr $word $i 1`

		#	if there's a "0", then shuffle this dice[i-1]
		if [ "$sign" == "0" ]; then
			dices[$i-1]=`expr $RANDOM % 6 + 1`
		fi
	done

	#	modified dices
	#echo " #2: ${dices[*]}"
}

#--- bonus 1: implementing parameters, like a helping method or print the author or else
function analyzingParameters() {
	case $1 in
		"-h")
				cat help.txt
			;;
		"-a")
			echo -e " author: $AUTHOR\n version: $VERSION\n It's designed for the programming tutorial \"bash programming\""
			echo " available on YouTube."
			;;
	esac

	echo " The program will now terminate."
	exit 0
}

#---------
# test outputs
#---------
#shuffleDices
#echo "points = $points"
#onSingleEyes 1                     (works; same for 2, 3, ..., 6)
#onOfAKind_N $FOUR_OF_A_KIND        (works; same for THREE_OF_A_KIND)
#onFullHouse                        (works)
#onStraight $LARGE_STRAIGHT         (works)
#onYahtzee                          (works)
#onChance                           (works)
#shuffleDices                       (works)

#points=$((points + $?))
#echo "points = $points"
#---------

#---------
# for helping usage
#---------
if [ "$1" == "-h" ] || [ "$1" == "-a" ]; then
	analyzingParameters $1
else
	echo " if you need some help, then run the program with -h"
fi

echo
#---------

#---------
# main game
#---------
subPoints=0

#--- bonus 2
# the user may reshuffle the dices up to two times
retries=0

# repeat 13 times to play each sub win
while [ $nbrOfRounds -ne 13 ]; do
	# shuffle the dices
    shuffleDices

    printCurrentDices

    #--- bonus 2: offer the user to shuffle the dices again, if the combination is worse
    while [ $retries -lt 2 ]; do
    	read -p " Would you like to shuffle again? <y/n> " answer

    	if [ $answer == 'y' ]; then

    		#--- bonus 3: offer the user to select which dices shall be shuffled again
    		convertInput

    		#--- bonus 2
    		retries=$(($retries + 1))
    		printCurrentDices
    	else
    		retries=0
    		break
    	fi
    done

    #--- reset the number of retries, if needed
    if [ $retries -gt 0 ]; then
    	retries=0
    fi

	#for option in ${tuplesNames[*]}; do
	#	echo " $option"
	#done

    for ((i=0; i < 13; i++)) do
        if [ ${markForSubWins[$i]} == $ALIVE ]; then
            option=${tuplesNames[$i]}
            echo " `expr $i + 1`) $option "
        fi
    done

    read -p " select your option: " choosenInput
    #echo " -------> $choosenInput"

    case $choosenInput in
        1)
            onSingleEyes 1
        ;;
        2)
            onSingleEyes 2
        ;;
        3)
            onSingleEyes 3
        ;;
        4)
            onSingleEyes 4
        ;;
        5)
            onSingleEyes 5
        ;;
        6)
            onSingleEyes 6
        ;;
        7)
            onOfAKind_N $THREE_OF_A_KIND
        ;;
        8)
            onOfAKind_N $FOUR_OF_A_KIND
        ;;
        9)
            onFullHouse
        ;;
        10)
            onStraight $SMALL_STRAIGHT
        ;;
        11)
            onStraight $LARGE_STRAIGHT
        ;;
        12)
            onYahtzee
        ;;
        13)
            onChance
        ;;
    esac

    subPoints=$?
    echo " gotten points: $subPoints"
    
    points=`expr $points + $subPoints`
    echo " sum of all points: $points"
    
    nbrOfRounds=$(($nbrOfRounds + 1))
done
