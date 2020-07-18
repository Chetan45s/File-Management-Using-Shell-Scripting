#!/usr/bin/bash

echo "--------------Welcome to your Diary--------------"

ch=0
while [ $ch -lt 8 ]
do
    echo "1. Enter 1 if you want to read your existed file."
    echo "2. Enter 2 if you want to create a new file."
    echo "3. Enter 3 if you want to write someting in a file."
    echo "4. Enter 4 if you want to list the files."
    echo "5. Enter 5 if you want to encrypt the files."
    echo "6. Enter 6 if you want to decrypt the files."
    echo "7. Enter 7 if you dont want to continue."

    read ch

    case $ch in
    1) echo " "
       echo -e "Enter name of you file : \c"
       read file_name

       if [ -f $file_name ]
       then
            if [ -s $file_name ]
            then
                while read p
                do
                    echo $p
                done < $file_name
            else
                echo "File is empty."
                echo "Please exit and write someting in "$filename
            fi
        else
            echo "File does not exit."
            echo "Please create a file first"
            echo " "
        fi
        echo " "
        echo "-------------------------------------------------"
    ;;
    
    2) echo " "
       echo "Create a new file"
       echo " "
       echo -e "Enter the name of your file : \c"
       read file_name1
       
       if [ -e $file_name1 ]
       then
            echo "File already existed"
       else
            touch $file_name1
       fi
       echo " "
    ;;

    3) echo " "
       echo " Write something in a file "
       echo " "
       echo -e "Enter the name of the file : \c"
       read file_name2

       if [ -f $file_name2 ]
       then
            if [ -w $file_name2 ]
            then
                echo "Type some text data. To quit press ctrl+d. "
                cat >> $file_name2
            else
                chmod +w $file_name2
            fi
        else
            echo "File does not exit."
            echo "Please create a file first"
            echo " "
        fi
    ;;
    4) ls -s;;
    5) echo " "
       echo "Encrypting the file with password"
       echo " "
       echo -e "Enter the file name which you want to encrypt : \c"
       read f
       mcrypt $f
       rm $f
       echo " "
       echo "File is encrypted successfully."
       echo " "
       echo "--------------------------------------------------------"
       echo " "
    ;;
    6) echo " "
       echo "Decrypting the file with password"
       echo " "
       echo -e "Enter the file name which you want to Decrypt (yourfilemame.nc) : \c"
       read f1
       mcrypt -d $f1
       rm $f1
       echo " "
       echo "File is decrypted successfully."
       echo " "
       echo "--------------------------------------------------------"
       echo " " 
    ;;
    7) echo " "
       echo "Exiting..."
       echo " "
       exit
    ;;
    esac
done