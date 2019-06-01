
#!/bin/bash



declare -A colors_list


# Reset
# Text Reset
colors_list["Color_Off"]='\033[0m'
colors_list["color_off"]='\033[0m'
colors_list["no_color"]='\033[0m'
colors_list["nc"]='\033[0m'
colors_list["NC"]='\033[0m'

# Regular colors_list
colors_list["Black"]='\033[0;30m'			# black
colors_list["Red"]='\033[0;31m'				# red
colors_list["Green"]='\033[0;32m'			# green
colors_list["Yellow"]='\033[0;33m'			# yellow
colors_list["Blue"]='\033[0;34m'			# blue
colors_list["Purple"]='\033[0;35m'			# purple
colors_list["Cyan"]='\033[0;36m'			# cyan
colors_list["White"]='\033[0;37m'			# white
colors_list["black"]='\033[0;30m'			# black
colors_list["red"]='\033[0;31m'				# red
colors_list["green"]='\033[0;32m'			# green
colors_list["yellow"]='\033[0;33m'			# yellow
colors_list["blue"]='\033[0;34m'			# blue
colors_list["purple"]='\033[0;35m'			# purple
colors_list["cyan"]='\033[0;36m'			# cyan
colors_list["white"]='\033[0;37m'			# white

# Bold
colors_list["BBlack"]='\033[1;30m'			# bold black
colors_list["BRed"]='\033[1;31m'			# bold red
colors_list["BGreen"]='\033[1;32m'			# bold green
colors_list["BYellow"]='\033[1;33m'			# bold yellow
colors_list["BBlue"]='\033[1;34m'			# bold blue
colors_list["BPurple"]='\033[1;35m'			# bold purple
colors_list["BCyan"]='\033[1;36m'			# bold cyan
colors_list["BWhite"]='\033[1;37m'			# bold white
colors_list["b_black"]='\033[1;30m'			# bold black
colors_list["b_red"]='\033[1;31m'			# bold red
colors_list["b_green"]='\033[1;32m'			# bold green
colors_list["b_yellow"]='\033[1;33m'		# bold yellow
colors_list["b_blue"]='\033[1;34m'			# bold blue
colors_list["b_purple"]='\033[1;35m'		# bold purple
colors_list["b_cyan"]='\033[1;36m'			# bold cyan
colors_list["b_white"]='\033[1;37m'			# bold white

# Underline
colors_list["UBlack"]='\033[4;30m'			# underline black
colors_list["URed"]='\033[4;31m'			# underline red
colors_list["UGreen"]='\033[4;32m'			# underline green
colors_list["UYellow"]='\033[4;33m'			# underline yellow
colors_list["UBlue"]='\033[4;34m'			# underline blue
colors_list["UPurple"]='\033[4;35m'			# underline purple
colors_list["UCyan"]='\033[4;36m'			# underline cyan
colors_list["UWhite"]='\033[4;37m'			# underline white
colors_list["u_black"]='\033[4;30m'			# underline black
colors_list["u_red"]='\033[4;31m'			# underline red
colors_list["u_green"]='\033[4;32m'			# underline green
colors_list["u_yellow"]='\033[4;33m'		# underline yellow
colors_list["u_blue"]='\033[4;34m'			# underline blue
colors_list["u_purple"]='\033[4;35m'		# underline purple
colors_list["u_cyan"]='\033[4;36m'			# underline cyan
colors_list["u_white"]='\033[4;37m'			# underline white

# Background
colors_list["On_Black"]='\033[40m'			# background black
colors_list["On_Red"]='\033[41m'			# background red
colors_list["On_Green"]='\033[42m'			# background green
colors_list["On_Yellow"]='\033[43m'			# background yellow
colors_list["On_Blue"]='\033[44m'			# background blue
colors_list["On_Purple"]='\033[45m'			# background purple
colors_list["On_Cyan"]='\033[46m'			# background cyan
colors_list["On_White"]='\033[47m'			# background white
colors_list["on_black"]='\033[40m'			# background black
colors_list["on_red"]='\033[41m'			# background red
colors_list["on_green"]='\033[42m'			# background green
colors_list["on_yellow"]='\033[43m'			# background yellow
colors_list["on_blue"]='\033[44m'			# background blue
colors_list["on_purple"]='\033[45m'			# background purple
colors_list["on_cyan"]='\033[46m'			# background cyan
colors_list["on_white"]='\033[47m'			# background white

# High Intensity
colors_list["IBlack"]='\033[0;90m'			# high intensity black
colors_list["IRed"]='\033[0;91m'			# high intensity red
colors_list["IGreen"]='\033[0;92m'			# high intensity green
colors_list["IYellow"]='\033[0;93m'			# high intensity yellow
colors_list["IBlue"]='\033[0;94m'			# high intensity blue
colors_list["IPurple"]='\033[0;95m'			# high intensity purple
colors_list["ICyan"]='\033[0;96m'			# high intensity cyan
colors_list["IWhite"]='\033[0;97m'			# high intensity white
colors_list["i_black"]='\033[0;90m'			# high intensity black
colors_list["i_red"]='\033[0;91m'			# high intensity red
colors_list["i_green"]='\033[0;92m'			# high intensity green
colors_list["i_yellow"]='\033[0;93m'		# high intensity yellow
colors_list["i_blue"]='\033[0;94m'			# high intensity blue
colors_list["i_purple"]='\033[0;95m'		# high intensity purple
colors_list["i_cyan"]='\033[0;96m'			# high intensity cyan
colors_list["i_white"]='\033[0;97m'			# high intensity white

# Bold High Intensity
colors_list["BIBlack"]='\033[1;90m'			# bold high intensity black
colors_list["BIRed"]='\033[1;91m'			# bold high intensity red
colors_list["BIGreen"]='\033[1;92m'			# bold high intensity green
colors_list["BIYellow"]='\033[1;93m'		# bold high intensity yellow
colors_list["BIBlue"]='\033[1;94m'			# bold high intensity blue
colors_list["BIPurple"]='\033[1;95m'		# bold high intensity purple
colors_list["BICyan"]='\033[1;96m'			# bold high intensity cyan
colors_list["BIWhite"]='\033[1;97m'			# bold high intensity white
colors_list["b_i_black"]='\033[1;90m'		# bold high intensity black
colors_list["b_i_red"]='\033[1;91m'			# bold high intensity red
colors_list["b_i_green"]='\033[1;92m'		# bold high intensity green
colors_list["b_i_yellow"]='\033[1;93m'		# bold high intensity yellow
colors_list["b_i_blue"]='\033[1;94m'		# bold high intensity blue
colors_list["b_i_purple"]='\033[1;95m'		# bold high intensity purple
colors_list["b_i_cyan"]='\033[1;96m'		# bold high intensity cyan
colors_list["b_i_white"]='\033[1;97m'		# bold high intensity white

# High Intensity backgrounds
colors_list["On_IBlack"]='\033[0;100m'		# high intensity background black
colors_list["On_IRed"]='\033[0;101m'		# high intensity background red
colors_list["On_IGreen"]='\033[0;102m'		# high intensity background green
colors_list["On_IYellow"]='\033[0;103m'		# high intensity background yellow
colors_list["On_IBlue"]='\033[0;104m'		# high intensity background blue
colors_list["On_IPurple"]='\033[0;105m'		# high intensity background purple
colors_list["On_ICyan"]='\033[0;106m'		# high intensity background cyan
colors_list["On_IWhite"]='\033[0;107m'		# high intensity background white
colors_list["on_i_black"]='\033[0;100m'		# high intensity background black
colors_list["on_i_red"]='\033[0;101m'		# high intensity background red
colors_list["on_i_green"]='\033[0;102m'		# high intensity background green
colors_list["on_i_yellow"]='\033[0;103m'	# high intensity background yellow
colors_list["on_i_blue"]='\033[0;104m'		# high intensity background blue
colors_list["on_i_purple"]='\033[0;105m'	# high intensity background purple
colors_list["on_i_cyan"]='\033[0;106m'		# high intensity background cyan
colors_list["on_i_white"]='\033[0;107m'		# high intensity background white


# usage:
# cecho some text "green" "on_red"
function cecho_old()
{
		local text_data=$1
		local color1=$2
		local color2=$3
		local color1_exp=""
		local color2_exp=""
		local color_reset_exp=""
		local NC='\033[0m'

		color_reset_exp=${colors_list["Color_Off"]}

		if [[ $color1 == "" ]]
		then
				color1="White"
				color2_exp=""
				#color1_exp=${colors_list[$color1]}
		else
				color1_exp=${colors_list[$color1]}
				if [[ $color2 == "" ]]
				then
						color2=""
						color2_exp=""
				else
						color2_exp=${colors_list[$color2]}
				fi
		fi

		#color1_exp=${colors_list[$color1]}
		#echo -e -n ${colors_list[$color1]}
		#echo -e -n ${colors_list[$color2]}
		echo -e -n $color1_exp
		echo -e -n $color2_exp
		echo -n $text_data
		echo -e  $color_reset_exp
		#echo -e -n ${colors_list["Color_Off"]}
		#echo $NC
		#printf "${!1}${2} ${NC}\n"
}


function cechoe()
{
		local text_data=$1
		local color1=$2
		local color2=$3
		local color1_exp=""
		local color2_exp=""
		local color_reset_exp=""
		local NC='\033[0m'

		color_reset_exp=${colors_list["Color_Off"]}

		if [[ $color1 == "" ]]
		then
				color1="White"
				color2_exp=""
				#color1_exp=${colors_list[$color1]}
		else
				color1_exp=${colors_list[$color1]}
				if [[ $color2 == "" ]]
				then
						color2=""
						color2_exp=""
				else
						color2_exp=${colors_list[$color2]}
				fi
		fi

		#color1_exp=${colors_list[$color1]}
		#echo -e -n ${colors_list[$color1]}
		#echo -e -n ${colors_list[$color2]}
		echo -e -n $color1_exp
		echo -e -n $color2_exp
		echo -n -e $text_data
		echo -e  $color_reset_exp
		#echo -e -n ${colors_list["Color_Off"]}
		#echo $NC
		#printf "${!1}${2} ${NC}\n"
}



function cecho_old()
{
		local text_data=$1
		local color1=$2
		local color2=$3
		local color1_exp=""
		local color2_exp=""
		local color_reset_exp=""
		local NC='\033[0m'

		local args=$4
		local args_iterator=1
		local args_num=${#@}

		local arg_flag_n="FALSE"
		local arg_flag_e="FALSE"
		local echo_args=""

		declare -A TMP_ARRAY

		while (( $args_iterator <= ${#@} ))
		do
			eval "tmp_arg=$"$args_iterator
			eval "TMP_ARRAY[$args_iterator]='"$tmp_arg"'"
			let args_iterator=args_iterator+1
		done

		let args_iterator=1
		let data_colors_flag=0
		color1=""
		color2=""
		text_data=""

		while (( $args_iterator <= $args_num ))
		do
			arg=${TMP_ARRAY[$args_iterator]}
			#echo ${TMP_ARRAY[$args_iterator]}
			let args_iterator=args_iterator+1
			is_arg=`printf "%s" $arg | grep -E "^[-]{1,2}[a-z]{1,3}" -o`
			if [[ $is_arg == "" ]]
			then
				let data_colors_flag=data_colors_flag+1
				if (( $data_colors_flag == 1 ))
				then
					text_data=$arg
					continue
				fi
				if (( $data_colors_flag == 2 ))
				then
					color1=$arg
					continue
				fi
				if (( $data_colors_flag == 3 ))
				then
					color2=$arg
					continue
				fi
			fi
			if [[ $is_arg == "-n" ]]
			then
				arg_flag_n="TRUE"
				echo_args=$echo_args" -n"
				continue
			fi
			if [[ $is_arg == "-e" ]]
			then
				arg_flag_e="TRUE"
				echo_args=$echo_args" -e "
				continue
			fi
		done

		#TMP_ARRAY[1]=$1
		#TMP_ARRAY[2]=$2
		#TMP_ARRAY[3]=$3
		#echo ${TMP_ARRAY[1]}
		#echo ${TMP_ARRAY[2]}
		#echo ${#@}
		#exit

		#local cmd_args=""
		#if [[ $4 == "" ]]
		#then
		#	cmd_args=$( printf "%s" $3 | grep -E "[-]{1,2}[a-z]{1,3}" -o --color )
		#else
		#	cmd_args=$( printf "%s" $4 | grep -E "[-]{1,2}[a-z]{1,3}" -o --color )
		#fi

		#echo $3 | grep -E "\-"

		color_reset_exp=${colors_list["Color_Off"]}

		# for arg in $@
		# do
		# 	echo "$arg"
		# done

		# exit

		if [[ $color1 == "" ]]
		then
				color1="White"
				color2_exp=""
				#color1_exp=${colors_list[$color1]}
		else
				color1_exp=${colors_list[$color1]}
				if [[ $color2 == "" ]]
				then
						color2=""
						color2_exp=""
				else
						color2_exp=${colors_list[$color2]}
				fi
		fi

		#color1_exp=${colors_list[$color1]}
		#echo -e -n ${colors_list[$color1]}
		#echo -e -n ${colors_list[$color2]}
		#echo -n $text_data
		#echo -e -n ${colors_list["Color_Off"]}
		#echo $NC
		#printf "${!1}${2} ${NC}\n"

		if (( 0 ))
		then
			echo -e -n $color1_exp
			echo -e -n $color2_exp
			echo -n $text_data
			echo -e  $color_reset_exp
		fi

		echo -e -n $color1_exp
		echo -e -n $color2_exp
		echo $echo_args $text_data
		echo -e  -n $color_reset_exp
}



function cecho()
{
		local text_data=""
		local color1=""
		local color2=""
		local color1_exp=""
		local color2_exp=""
		local color_reset_exp=""

		local args_iterator=1
		local data_colors_flag=0
		local args_num=${#@}
		local tmp_arg=""

		local echo_args=""

		declare -A TMP_ARRAY

		while (( $args_iterator <= $args_num ))
		do
			eval "tmp_arg=$"$args_iterator
			eval "TMP_ARRAY[$args_iterator]='"$tmp_arg"'"
			let args_iterator=args_iterator+1
		done

		let args_iterator=1
		let data_colors_flag=0

		while (( $args_iterator <= $args_num ))
		do
			arg=${TMP_ARRAY[$args_iterator]}
			#echo ${TMP_ARRAY[$args_iterator]}
			let args_iterator=args_iterator+1
			is_arg=`printf "%s" $arg | grep -E "^[-]{1,2}[a-z]{1,3}" -o`
			if [[ $is_arg == "" ]]
			then
				let data_colors_flag=data_colors_flag+1
				if (( $data_colors_flag == 1 ))
				then
					text_data=$arg
					continue
				fi
				if (( $data_colors_flag == 2 ))
				then
					color1=$arg
					continue
				fi
				if (( $data_colors_flag == 3 ))
				then
					color2=$arg
					continue
				fi
			fi
			if [[ $is_arg == "-n" ]]
			then
				arg_flag_n="TRUE"
				echo_args=$echo_args" -n"
				continue
			fi
			if [[ $is_arg == "-e" ]]
			then
				arg_flag_e="TRUE"
				echo_args=$echo_args" -e "
				continue
			fi
		done

		color_reset_exp=${colors_list["color_off"]}

		if [[ $color1 == "" ]]
		then
				color1="White"
				color2_exp=""
		else
				color1_exp=${colors_list[$color1]}
				if [[ $color2 == "" ]]
				then
						color2=""
						color2_exp=""
				else
						color2_exp=${colors_list[$color2]}
				fi
		fi

		echo -e -n $color1_exp
		echo -e -n $color2_exp
		echo $echo_args $text_data
		echo -e -n $color_reset_exp
}


