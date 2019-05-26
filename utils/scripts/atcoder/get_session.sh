#!/bin/bash
LOGIN_URL="https://atcoder.jp/login"
CSRF_ELEMENT=$(curl -c login.cookie ${LOGIN_URL} | grep csrf_token | head -1)
CSRF_TOKEN=$(echo ${CSRF_ELEMENT} | sed -E "s/^.*value='(.*)'.*$/\1/")

printf "username: "
read USERNAME
printf "password: "
read -s PASSWORD
printf "\n"
curl -b login.cookie -c login.session -X POST -d "username=${USERNAME}" -d "password=${PASSWORD}" -d "csrf_token=${CSRF_TOKEN}" ${LOGIN_URL}
