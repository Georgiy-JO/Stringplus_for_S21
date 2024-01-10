#git commit -m'minor changies'
if [ "$1" -eq 1 ]
then
  git push origin feature/rk_jo_1
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push origin2 feature/rk_jo_1
elif [ $1 -eq 2 ]
then
  git push origin develop
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push origin2 develop
else
  echo ERROR command
fi


