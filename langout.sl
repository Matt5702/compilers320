.function main
main:
PUSH @$LANG_LABEL2
.dataseg
$LANG_LABEL2:
.string "alpha"
.codeseg
OUTS
PUSH @$LANG_LABEL3
.dataseg
$LANG_LABEL3:
.string "\n"
.codeseg
OUTS
PUSH @$LANG_LABEL4
.dataseg
$LANG_LABEL4:
.string "beta gamma"
.codeseg
OUTS
PUSH @$LANG_LABEL5
.dataseg
$LANG_LABEL5:
.string "\n"
.codeseg
OUTS
PUSH 123
CALL @print
SWAP
POP
POP
PUSH @$LANG_LABEL6
.dataseg
$LANG_LABEL6:
.string "done"
.codeseg
OUTS
PUSH @$LANG_LABEL7
.dataseg
$LANG_LABEL7:
.string "\n"
.codeseg
OUTS
PUSH 0
RETURNV
