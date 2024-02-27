#git commit -m'minor changies'
if [ "$1" -eq 1 ]
then
  git push origin feature/rk_jo_rework_check
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push origin2 feature/rk_jo_rework_check
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
else
  echo ERROR command
fi



