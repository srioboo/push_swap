ARG="111-1 2 -3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3333-3333 1 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="111+111 -4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="--123 1 321"; ./push_swap $ARG | ./checker_linux $ARG
ARG="++123 1 321"; ./push_swap $ARG | ./checker_linux $ARG

ARG="2 1"; ./push_swap $ARG | ./checker_linux $ARG


---- fail test
ARG="2 3 5 4 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 3 5 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 5 3 1"
ARG="2 5 3 4 1"
ARG="2 5 4 3 1"
ARG="3 5 4 1 2"
ARG="3 5 4 2 1"
ARG="5 4 3 1 2"
ARG="5 4 3 2 1"


ARG=$(seq 0 99 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
