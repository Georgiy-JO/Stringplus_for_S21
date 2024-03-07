#don't forget to commit (unless u use option 9)
VAR_FILE="double_push.variables.txt"
old_tec_com=$(<"$VAR_FILE")

if [ "$1" -eq 1 ]
then
  git push origin feature/rk_jo_release
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push origin2 feature/rk_jo_release
elif [ $1 -eq 2 ]
then
  git push origin develop
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push origin2 develop
elif [ $1 -eq 3 ]
then
  git push origin feature/rk_jo_2
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push origin2 feature/rk_jo_2
elif [ $1 -eq 4 ]
then
  git push origin feature/rk_jo_rework_check
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push origin2 feature/rk_jo_rework_check
elif [ $1 -eq 5 ]
then
  git push origin feature/rk_jo_final
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push origin2 feature/rk_jo_final
elif [ $1 -eq 9 ]
then
  new_tec_com=$((old_tec_com + 1))
  echo "$new_tec_com" > $VAR_FILE
  git add src double_push.variables.txt
  git commit -m"Technical commit #"$new_tec_com": Minor changies."
  git push origin develop
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push origin2 develop
else
  echo ERROR command
fi



