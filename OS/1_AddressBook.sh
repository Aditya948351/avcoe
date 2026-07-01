#!/bin/bash

FILE="addressbook.txt"

createAddressBook() {
    if [ -e "$FILE" ]; then
        echo "Address book already exists."
    else
        touch "$FILE"
        echo "Address book created."
    fi
}

viewAddressBook() {
    if [ ! -s "$FILE" ]; then
        echo "Address book is empty or does not exist."
    else
        echo "---- Address Book ----"
        cat "$FILE"
    fi
}

insertRecord() {
    echo "Enter record in format: LastName,FirstName,Email,Phone"
    read record
    echo "$record" >> "$FILE"
    echo "Record inserted."
}

deleteRecord() {
    if [ ! -s "$FILE" ]; then
        echo "Address book is empty or does not exist."
        return
    fi

    echo "Enter a search string (e.g. name or email) to find the record to delete:"
    read search
    matches=$(grep -n "$search" "$FILE")

    if [ -z "$matches" ]; then
        echo "No matching records found."
        return
    fi

    echo "$matches"
    echo "Enter line number to delete:"
    read line
    sed -i "${line}d" "$FILE"
    echo "Record deleted."
}

modifyRecord() {
    if [ ! -s "$FILE" ]; then
        echo "Address book is empty or does not exist."
        return
    fi

    echo "Enter a search string (e.g. name or email) to find the record to modify:"
    read search
    matches=$(grep -n "$search" "$FILE")

    if [ -z "$matches" ]; then
        echo "No matching records found."
        return
    fi

    echo "$matches"
    echo "Enter line number to modify:"
    read line
    echo "Enter new record (LastName,FirstName,Email,Phone):"
    read newRecord
    sed -i "${line}s/.*/$newRecord/" "$FILE"
    echo "Record modified."
}

exitProgram() {
    echo "Exiting... Goodbye!"
    exit 0
}

while true; do
    echo "1. Create Address Book"
    echo "2. View Address Book"
    echo "3. Insert a Record"
    echo "4. Delete a Record"
    echo "5. Modify a Record"
    echo "6. Exit"
    echo "=============================="
    echo -n "Enter your choice: "
    read choice

    case $choice in
        1) createAddressBook ;;
        2) viewAddressBook ;;
        3) insertRecord ;;
        4) deleteRecord ;;
        5) modifyRecord ;;
        6) exitProgram ;;
        *) echo "Invalid choice. Please select 1-6." ;;
    esac
done
