int ASCII_to_index_3x5
(
    int ASCII_CODE
)
{
    if(ASCII_CODE >= 48 && ASCII_CODE <= 57){
        return ASCII_CODE - 48;
    }
    else if(ASCII_CODE >= 65 && ASCII_CODE <= 90){
        return ASCII_CODE - 55;
    }
    else{
        return -1;
    }
}