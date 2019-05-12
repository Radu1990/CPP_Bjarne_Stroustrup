// other.cpp
// Exercises from "Programming: Principles and Practice Using C++ (English Edition)" by Bjarne Stroustrup
#include "other.h"
#include "std_lib_facilities.h"

// Drill
void MyDrill()
{
    cout << "Please enter the name you want to write to (followed by 'enter'):\n";
    string first_name;
    cin >> first_name;
    cout << "Dear " << first_name << ",\n\n";
    cout << "   How are you? Do you want to go for a Starbucks coffee sometime?\n"
         << "   I really want to try the Caramel Machiatto this time :D\n";
    cout << "Please enter the name of a close friend (followed by 'enter'):\n";
    string friend_name;
    cin >> friend_name;
    cout << "   Have you seen " << friend_name << " lately?\n";
    char friend_sex{0};
    cout << "Is your friend a male or a female? Type m for male or f for female (followed by 'enter'):\n";
    cin >> friend_sex;
    if (friend_sex == 'f') {
        cout << "If you see " << friend_name << " please tell her to call me!\n";
        cout << "Oh and btw... How old was she?\n";
    }
    if (friend_sex == 'm') {
        cout << "If you see " << friend_name << " please tell him to call me!\n";
        cout << "Oh and btw... How old was he?\n";
    }
    int friend_age{0};
    cin >> friend_age;
    if (friend_age <= 0 || friend_age >= 110) {
        simple_error("You're kidding! :))\n");
    }
    if (friend_sex == 'f') {
        cout << "I just heard that she had a birthday and she is " << friend_age << " years old!\n";
    }
    if (friend_sex == 'm') {
        cout << "I just heard that he had a birthday and he is " << friend_age << " years old!\n";
    }
    if (friend_age < 12 && friend_sex == 'f') {
        cout << "Next year she will be " << friend_age + 1 << "!\n";
    }
    if (friend_age < 12 && friend_sex == 'm') {
        cout << "Next year he will be " << friend_age + 1 << "!\n";
    }
    if (friend_age == 17 && friend_sex == 'f') {
        cout << "Next year she will be able to vote!\n";
    }
    if (friend_age == 17 && friend_sex == 'm') {
        cout << "Next year he will be able to vote!\n";
    }
    if (friend_age > 70 && friend_sex == 'f') {
        cout << "I hope she is enjoying retirement!\n";
    }
    if (friend_age > 70 && friend_sex == 'm') {
        cout << "I hope he is enjoying retirement!\n";
    }
    string senderName {"John Doe"};
    cout << "What was your name again?\n";
    cin >> senderName;
    cout << "\n\nYours sincerely,\n" << senderName << "\n";
}

string EdekaInstructions()
{
    string a;
    a = "You are in your car on the street and want to drive to the'Edeka' Supermarket\n"
        "Drive on Hopfauer Str. and make a left turn on the first intersection\n"
        "Drive forward on Schopflocher Str. up to Kaltentaler Str. and then make a right turn\n"
        "Drive forward on Kaltentaler Str. and then make a left turn on Paradies Str.\n"
        "Turn left in the intersection\n"
        "Drive on Paradies Str up to Rottweiler Str. and then make a right\n"
        "Drive on Rottweiler Str. up to Haupt Str. and then make a right\n"
        "Drive on Haupt Str. and slowly move on the left lane up to the next intersection\n"
        "Make a left on Robert Koch Str.\n"
        "Drive on Robert Koch Str. and make a left on Emilien Str.\n"
        "Drive on Emilien Str. and make a left on Sigmund Str.\n"
        "Turn right and enter the Parkplatz of Edeka\n"
        "Have fun shopping!\n";
    return a;
}

string bathroomInstructions()
{
    string a;
    a= "Hello, programing!\nHere we go!\n"
       "Instructions for going to the bathroom\n"
       "1. Place both feet on the ground\n"
       "2. Move Chair to the back slightly until it touches the bed with the backrest\n"
       "3. Turn with the chair 45 degrees to the right\n"
       "4. Stand up\n"
       "5. Walk to the door\n"
       "6. Grab door handle with left arm softly\n"
       "7. Open door by turning handle down 15 degrees around the door handle axis\n"
       "8. Make sure there is enough space between body and the door to open the door\n"
       "If not go required remaining space back\n"
       "9. Pull door to the back around the door's axis 80 degrees\n"
       "10. Let go of the door handle\n"
       "11. Move 1.5 meters to the front up to the main hallway\n"
       "12. Rotate body 90 degrees to the left\n"
       "13. Move 1.5 meters to the front up to the bathroom door\n"
       "14. Grab door handle with left arm softly\n"
       "15. Open door by turning handle down 15 degrees around the door handle axis\n"
       "16. Make sure there is enough space between body and the door to open the door\n"
       "If not go required remaining space back\n"
       "17. Pull door to the back around the door's axis 80 degrees\n"
       "18. Let go of the door handle\n"
       "19. Move 0.5 meters to the front\n"
       "Congratulations! You are in the bathroom!\n";
    return a;
}


void runEdekaInstructions() {
    string a;
    a = EdekaInstructions();
    cout << a;
}
void runBathroomInstructions() {
    string b;
    b = bathroomInstructions();
    cout << b;
}

void someComputing() {
    cout << "Please enter a floating-point value: ";
    double n;
    cin >> n;
    cout << "n == " << n
         << "\nn+1 == " << n + 1
         << "\nthree times n == " << n * 3
         << "\ntwice n == " << n * 2
         << "\nn squared == " << n * n
         << "\nhalf of n == "  << n / 2
         << "\nsquare root of n == " << sqrt(n)
         << "\n";
}
// TODO
// Try to make a separate counter for each word
void checkRepeatedWord() {
    cout << "Type a sentence containing words that repeat\n";
    string previous = " "; // previous word; zed to "not a word"
    string current;
    int charRepeatedWord = 1;
    while (cin >> current) { // current word
        if (previous == current) {
            cout << "Word: " << current << "\n";
            ++charRepeatedWord;
            cout << "Repetitions: " << charRepeatedWord << "\n";
        }
        previous = current;
    }
}

void unsafeConversions() {
    cout << "Type a char here: \n";
    double d = 0;
    while (cin >> d) {
        int i = d;
        char c = i;
        int i2 = c;
        cout << "d== " << d
             << "\ni== " << i
             << "\ni2== " << i2
             << "\nchar(" << c << ")\n";
    }
}

void convertKmiles() {
    cout << "This program converts miles to km and km to miles\n";
    char km_or_miles {'0'};
    cout << "Unit to be converted: (type m for mile or k for km)\n";
    cin >> km_or_miles;
    if (km_or_miles == 'm') {
        double miles {0};
        double km {0};
        cout << "Please enter char of miles to be converted:\n";
        cin >> miles;
        km = miles * 1.609;
        cout << miles << " miles" << " == " << km << " km\n";
    }
    if (km_or_miles == 'k') {
        double miles {0};
        double km {0};
        cout << "Please enter char of kilometers to be converted:\n";
        cin >> km;
        miles = km / 1.609;
        cout << km << " km" << " == " << miles << " miles\n";
    }
}

void orderIntegerValues() {
    cout << "Please enter 3 integer values: \n";
    int val1, val2, val3 {0};
    int val_1_ord, val_2_ord, val_3_ord {0};
    cin >> val1 >> val2 >> val3;

    // val_1_assignment
    if (val1 <= val2 && val1 <= val3) {
        val_1_ord = val1;
    }
    if (val2 <= val1 && val2 <= val3) {
        val_1_ord = val2;
    }
    if (val3 <= val1 && val3 <= val2) {
        val_1_ord = val3;
    }

    // val_2_ord assignment
    // val 1
    if (val1 >= val2 && val1 <= val3) {
        val_2_ord = val1;
    }
    if (val1 <= val2 && val1 >= val3) {
        val_2_ord = val1;
    }
    // val 2
    if (val2 >= val1 && val2 <= val3) {
        val_2_ord = val2;
    }
    if (val2 <= val1 && val2 >= val3) {
        val_2_ord = val2;
    }
    // val 3
    if (val3 >= val1 && val3 <= val2) {
        val_2_ord = val3;
    }
    if (val3 <= val1 && val3 >= val2) {
        val_2_ord = val3;
    }

    // val_3_ord assignment
    if (val1 >= val2 && val1 >= val3) {
        val_3_ord = val1;
    }
    if (val2 >= val1 && val2 >= val3) {
        val_3_ord = val2;
    }
    if (val3 >= val1 && val3 >= val2) {
        val_3_ord = val3;
    }
    cout << "Increasingly ordered integers: " << "[" << val_1_ord << ", " << val_2_ord << ", " << val_3_ord << "]";

}

void orderStringValues() {
    cout << "Please enter 3 string values: \n";
    string val1, val2, val3 {" "};
    string val_1_ord, val_2_ord, val_3_ord {" "};
    cin >> val1 >> val2 >> val3;

    // val_1_assignment
    if (val1 <= val2 && val1 <= val3) {
        val_1_ord = val1;
    }
    if (val2 <= val1 && val2 <= val3) {
        val_1_ord = val2;
    }
    if (val3 <= val1 && val3 <= val2) {
        val_1_ord = val3;
    }

    // val_2_ord assignment
    // val 1
    if (val1 >= val2 && val1 <= val3) {
        val_2_ord = val1;
    }
    if (val1 <= val2 && val1 >= val3) {
        val_2_ord = val1;
    }
    // val 2
    if (val2 >= val1 && val2 <= val3) {
        val_2_ord = val2;
    }
    if (val2 <= val1 && val2 >= val3) {
        val_2_ord = val2;
    }
    // val 3
    if (val3 >= val1 && val3 <= val2) {
        val_2_ord = val3;
    }
    if (val3 <= val1 && val3 >= val2) {
        val_2_ord = val3;
    }

    // val_3_ord assignment
    if (val1 >= val2 && val1 >= val3) {
        val_3_ord = val1;
    }
    if (val2 >= val1 && val2 >= val3) {
        val_3_ord = val2;
    }
    if (val3 >= val1 && val3 >= val2) {
        val_3_ord = val3;
    }
    cout << "Increasingly ordered strings: " << "[" << val_1_ord << ", " << val_2_ord << ", " << val_3_ord << "]";
}

void oddEven() {
    cout << "This program checks if a char is odd or even\n";
    int inputValue {0};
    int checkValue {0};
    cout << "Please insert a positive integer:\n";
    cin >> inputValue;
    checkValue =  inputValue%2;
    if (checkValue == 0) {
        cout << "char is even! I like it!\n";
    }
    if (checkValue == 1) {
        cout << "char is odd! How odd!\n";
    }
}

void stringTochar() {
    string inputString {" "};
    cout << "This program converts spelled-out chars to numerical values\n";
    cout << "Please type in a char using only letters (using lower caps-letters):\n";
    cin >> inputString;
    if (inputString == "zero") {
        cout << "Input char: " << inputString <<  " == 0";
    }
    if (inputString == "one") {
        cout << "Input char: " << inputString <<  " == 1";
    }
    if (inputString == "two") {
        cout << "Input char: " << inputString <<  " == 2";
    }
    if (inputString == "three") {
        cout << "Input char: " << inputString <<  " == 3";
    }
    if (inputString == "four") {
        cout << "Input char: " << inputString <<  " == 4";
    }
    if (inputString != "zero" && inputString != "one" && inputString != "two" && inputString != "three" && inputString != "four") {
        cout << "Input char " << inputString <<  " == not a char I know...stupid computer! >.< ";
    }
}

void basicCalculator() {
    cout << "This program computes basic operations between 2 chars\n";
    cout << "Please enter an operation followed by two operands separated by spaces\nFor example:\n+ 100 3.14\n* 4 5\n";
    cout << "The order in which you enter the chars matters!\n";
    string operation {" "};
    double value_1 {0};
    double value_2 {0};
    cin >> operation >> value_1 >> value_2;
    if (operation == "+") {
        cout << value_1 << " plus " << value_2 << " is " << value_1 + value_2;
    }
    if (operation == "-") {
        cout << value_1 << " minus " << value_2 << " is " << value_1 - value_2;
    }
    if (operation == "*") {
        cout << value_1 << " multiplied by " << value_2 << " is " << value_1 * value_2;
    }
    if (operation == "/") {
        cout << value_1 << " divided by " << value_2 << " is " << value_1 / value_2;
    }
}

void switchStatement() {

    constexpr double cm_per_inch = 2.54;
    double length = 1;
    char unit = 'a';

    cout << "Please enter a length followed by a unit (c or i): \n";
    cin >> length >> unit;
    switch (unit) {
        case 'i' : {
            cout << length << " in == " << cm_per_inch * length << " cm\n";
            break;
        }
        case 'c' : {
            cout << length << " cm == " << length / cm_per_inch << " in\n";
            break;
        }
        default : {
            cout << " Sorry, I don't know a unit called '" << unit << "'\n";
            break;
        }
    }
}

void switchStatement_2() {
    cout << "Please enter a digit: \n";
    int a;
    cin >> a;

    switch (a) {
        case 0 :
        case 2 :
        case 4 :
        case 6 :
        case 8 : {
            cout << "is even\n";
            break;
        }
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 9 : {
            cout << "is odd!\n";
            break;
        }
        default :
            cout << "Is not a a single digit! \n";
            break;
    }
}

void tableCharacters() {
    cout << "Brief History of ASCII code:\n"
         << "If you want to read further press y if not press n to view the letters code\n";
    char x = 0;
    cin >> x;
    switch (x) {
        // this just lists some short history about ASCII
        case ('y') : {
            cout << "The American Standard Code for Information Interchange, or ASCII code,\n"
                    "was created in 1963 by the \"American Standards Association\" Comittee or \"ASA\",\n"
                    "the agency changed its name in 1969 by \"American National Standards Institute\" or \"ANSI\"\n"
                    "as it is known since.\n"
                    "\n"
                    "This code arises from reorder and expand the set of symbols and characters\n"
                    "already used in telegraphy at that time by the Bell company.\n"
                    "\n"
                    "At first only included capital letters and chars , but in 1967 was added the lowercase letters\n"
                    "and some control characters, forming what is known as US-ASCII, ie the characters 0 through 127.\n"
                    "So with this set of only 128 characters was published in 1967 as standard, containing all you need\n"
                    "to write in English language.\n"
                    "\n"
                    "In 1981, IBM developed an extension of 8-bit ASCII code, called \"code page 437\",\n"
                    "in this version were replaced some obsolete control characters for graphic characters.\n"
                    "Also 128 characters were added , with new symbols, signs, graphics and latin letters,\n"
                    "all punctuation signs and characters needed to write texts in other languages,\n"
                    "\u200B\u200Bsuch as Spanish.\n"
                    "In this way was added the ASCII characters ranging from 128 to 255.\n"
                    "\n"
                    "IBM includes support for this code page in the hardware of its model 5150, known as \"IBM-PC\",\n"
                    "considered the first personal computer.\n"
                    "The operating system of this model, the \"MS-DOS\" also used this extended ASCII code.\n"
                    "Almost all computer systems today use the ASCII code to represent characters and texts. (181) .";
            break;
        }
        // this lists the Aa-Zz ASCII Codes
        case ('n') : {
            cout << "\n";
            cout << "ASCII CODES FOR a-z letters:\n\n";

            char a = 'a'; // 'a' + 1 == 'b'; 'a' + 2 == 'c'  and so on...
            char A = 'A';

            for (int i = 97; i < 123; ++i, ++a) { // NEVER MODIFY THE LOOP VARIABLE INSIDE THE BODY OF A LOOP A FOR STATEMENT
                cout << a << "\t" << i << "\n";
            }
            cout << "\n";
            cout << "ASCII CODES FOR A-Z letters:\n\n";
            for (int i = 65; i < 91; ++i, ++A) { // NEVER MODIFY THE LOOP VARIABLE INSIDE THE BODY OF A LOOP OF A FOR STATEMENT
                cout << A << "\t" << i << "\n";
            }
            break;
        }
        // just the default case
        default : {
            cout << "Only options are 'y' or 'n' ...\n";
            break;
        }
    }
}

void printPowerSum(int x, int y) {
    // this function raises x to the power y by sumation
    int res {x};
    int i {0};
    if (y == 0) {
        cout << x << " ^ " << y << " == 1\n";
    }
    if (y != 0) {
        for (i = 1 ; i < y; i++ ) {
            res = res * x;
        }
        cout << x << " ^ " << y << " == " << res;
    }
}

void medianTemp() {
    cout << "This program computes temperature means (press any non-digit character to end input)\n\n";
    // creating an array of temperatures
    vector <double> temps;
    double median_temp {0.0};

    for (double temp; cin >> temp;) {
        temps.push_back(temp);
    }
    // compute average temperature
    double sum {0.0};
    for (double x : temps) { // this means for every x in range of temps which defined as an array
        sum += x;            // compute sum of elements
    }
    cout << "Average temperature: " << sum/temps.size() << " deg C \n\n";

    // compute median temperature
    sort(temps); // sort temperatures

    if (temps.size() % 2 == 1) {
        median_temp = temps[temps.size() / 2];
        cout << "Median temperature: " << median_temp << " deg C \n\n";
    }
    if (temps.size() % 2 == 0) {
        median_temp = ( temps[temps.size() / 2 ] + temps[temps.size() / 2 - 1] ) / 2;
        cout << "Median temperature: " << median_temp << " deg C \n\n";
    }
}

void printSortedWords() {
    vector <string> words;
    for (string word; cin >> word; ) {// read whitespace-separated words
        words.push_back(word);
    }
    cout << "char of words: " << words.size() << endl;
    sort(words);
    for (int i = 0; i < words.size(); ++i)  {
        if (i==0 || words[i-1] != words[i]) { // is this a new word ?
            cout << words[i] << "\n";
        }
    }
}

void bleepWords () {
    vector <string> words;
    string disliked {"broccoli"};
    int bleeped {0};
    for (string word; cin >> word; ) {// read whitespace-separated words
        if (word == disliked) {
            cout << "BLEEP" << "\n";
            ++bleeped;
            words.push_back("BLEEP!");
        }
        else {
            words.push_back(word);
        }
    }
    cout << "char of words: " << words.size() << endl;
    cout << "char of BLEEPED words: " << bleeped << endl;
    sort(words);
    for (int i = 0; i < words.size(); ++i)  {
        cout << words[i] << "\n";
    }
}

void drill_2() {
    cout << "This program compares chars, please insert char followed by measurement unit\n"
         << "Accepted units are: cm, in, ft and m and they will get converted to m\n\n";
    double input_value {0}; // this is the first value entered by the user
    string input_unit {" "};

    double largest_so_far {-123456789}; // this is the first value entered by the user
    double smallest_so_far {123456789}; // this is the second value entered by the user

    bool cond_1 {false};
    bool cond_2 {false};
    bool cond_3 {false};
    bool cond_4 {false};

    bool cond_input_unit {false};

    double difference_1 {0.000}; // this is the difference between the two input values when 1/2
    double difference_2 {0.000}; // this is the difference between the two input values when 2/1

    int counter_inputs {0};
    double sum_inputs {0};

    vector <double> valuesList;

    while (cin >> input_value >> input_unit ) {

        // BREAK!
        // trigger conditions:
        if (input_unit != "cm" && input_unit != "in" && input_unit!= "ft" && input_unit!= "m") {
            cond_input_unit = true;
        }
        if (cond_input_unit) {
            cout << "unit '" << input_unit << "' not accepted\n";
            break;
        }

        // RUN!!!

        else {
            cout << "The value entered is: " << input_value << input_unit << "\n";

            // transforming input to m
            if (input_unit == "cm") {
                input_value = input_value / 100 ;
            }
            if (input_unit == "in") {
                input_value = input_value * 2.54 / 100;
            }
            if (input_unit == "ft") {
                input_value = input_value * 12 * 2.54 / 100;
            }

            // adding to the vector
            valuesList.push_back(input_value);

            // checking if it is already in there
            if (input_value == largest_so_far) {
                cout << "Value equal to " << largest_so_far << " m\n";
            }
            if (input_value == smallest_so_far) {
                cout << "Value equal to " << smallest_so_far << " m\n";
            }

            // compute differences, these have to be computed before the values are allocated to the variables
            difference_1 = largest_so_far - input_value;
            difference_2 = input_value - smallest_so_far;
            // checking if it's smaller or bigger
            if (input_value < smallest_so_far) {
                cout << "The smallest value so far: " << input_value << " m after " << smallest_so_far << " m\n";
                smallest_so_far = input_value;
            }
            if (input_value > largest_so_far) {
                cout << "The largest value so far: " << input_value << " m after " << largest_so_far << " m\n";
                largest_so_far = input_value;
            }

            ++counter_inputs; // counter inputs
            cout << "Values entered so far: " << counter_inputs << "\n";

            sum_inputs += input_value; // add inputs
            cout << "Sum of values entered so far: " << sum_inputs << " m\n";

            // evaluating if chars are very close to each-other
            // cond 1
            if (0.000 < difference_1 && difference_1 < 0.010) {
                cond_1 = true;
            }
            // cond 2
            if (-0.010 < difference_1 && difference_1 < 0.000) {
                cond_2 = true;
            }
            // cond 3
            if (0.000 < difference_2 && difference_2 < 0.010) {
                cond_3 = true;
            }
            // cond 4
            if (-0.010 < difference_2 && difference_2 < 0.000) {
                cond_4 = true;
            }

            // conditions to be evaluated
            if (cond_1 || cond_2 || cond_3 || cond_4) {
                cout << "Comparing input to last largest and smallest values\n"
                     << "The chars are almost equal (difference < 0.01 )\n";
            }
            // switching conditions back to false
            cond_1 = false; cond_2 = false; cond_3 = false; cond_4 = false;
        }
        // printing values from the vector
        sort(valuesList);
        cout << "The vector elements are: [  ";
        for (int i = 0; i < valuesList.size(); i++) {
            cout << valuesList[i] << "  ";
        }
        cout << "]";
        //
    }
}

void distance_cities() {
    double input_value{0.0}; // distance for a given route between two cities

    double smallest_so_far{123456789}; // smallest distance so far
    double largest_so_far{-123456789}; // largest distance so far

    double total_distance{0.0};  // total
    double mean_distance{0.0}; // average distance overall between the two cities

    vector <double> distances_database;
    cout << "This program computes average distance between 2 cities (enter values in km)\n"
         << "Type a non-digit to end the file\n";

    while (cin >> input_value) {
        if (input_value < smallest_so_far) {
            cout << "The smallest value so far: " << input_value << " km after " << smallest_so_far << " km\n";
            smallest_so_far = input_value;
        }
        if (input_value > largest_so_far) {
            cout << "The largest value so far: " << input_value << " km after " << largest_so_far << " km\n";
            largest_so_far = input_value;
        }
        distances_database.push_back(input_value);
    }
    sort(distances_database);
    for (double x : distances_database) {
        total_distance = total_distance + x;
        mean_distance = total_distance / distances_database.size();
    }
    cout << "Total distance: " << total_distance << " km\n"
         << "Mean distance: " << mean_distance << " km\n"
         << "Smallest distance: " << distances_database[0] << " km\n"
         << "Largest distance: " << distances_database[distances_database.size() - 1] << " km\n";
}

void char_guess_game() {

    string answer {" "};
    //intro message
    cout << "Let's play the guessing game!\n"
         << "Think of a char between 1 and 10\n";
    // q 1
    cout << "Is it bigger than 5 ? Type 'y' for yes or 'n' for no\n";
    cin >> answer;
    if (answer == "y") {
        // char can be 6, 7, 8, 9 or 10
        cout << "Is it bigger than 8 ? Type 'y' for yes or 'n' for no\n";
        cin >> answer;
        if (answer == "y") {
            // char can be 9 or 10
            cout << "Is it bigger than 9 ? Type 'y' for yes or 'n' for no\n";
            cin >> answer;
            if (answer == "y") {
                cout << "char is 10\n";
            }
            if (answer == "n") {
                cout << "char is 9\n";
            }

        }
        if (answer == "n") {
            // char can be 6, 7, 8
            cout << "Is it bigger than 7 ? Type 'y' for yes or 'n' for no\n";
            cin >> answer;
            if (answer == "y") {
                cout << "The char is 8!\n";
            }
            if (answer == "n") {
                // char can be 6 or 7
                cout << "Is it bigger than 6 ? Type 'y' for yes or 'n' for no\n";
                cin >> answer;
                if (answer == "y") {
                    cout << "The char is 7!\n";
                }
                if (answer == "n") {
                    cout << "The char is 6!\n";
                }
            }
        }
    }
    if (answer == "n") {
        // char can be 1, 2 ,3 ,4 ,5
        cout << "Is it bigger than 3 ? Type 'y' for yes or 'n' for no\n";
        cin >> answer;
        if (answer == "y") {
            // char can be 4 or 5
            cout << "Is it bigger than 4 ? Type 'y' for yes or 'n' for no\n";
            cin >> answer;
            if (answer == "y") {
                cout << "The char is 5!\n";
            }
            if (answer == "n") {
                cout << "The char is 4!\n";
            }
        }
        if (answer == "n") {
            // char can be 1, 2, 3
            cout << "Is it bigger than 2 ? Type 'y' for yes or 'n' for no\n";
            cin >> answer;
            if (answer == "y") {
                cout << "The char is 3!\n";
            }
            if (answer == "n") {
                cout << "Is it bigger than 1 ? Type 'y' for yes or 'n' for no\n";
                cin >> answer;
                if (answer == "y") {
                    cout << "The char is 2!\n";
                }
                if (answer == "n") {
                    cout << "The char is 1!\n";
                }
            }
        }
    }
}

void digit_to_spelling() {
    vector <string> digit_strings {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector <string> digit_chars {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    string input_user {};

    cout << "This program converts digits to strings and viceversa\n"
         << "Please type a digit from 0-9 or zero-nine\n";
    while (cin >> input_user) {
        // digit - spelling
        if (input_user == digit_strings[0]) {
            cout << digit_chars[0] << "\n";
        }
        if (input_user == digit_strings[1]) {
            cout << digit_chars[1] << "\n";
        }
        if (input_user == digit_strings[2]) {
            cout << digit_chars[2] << "\n";
        }
        if (input_user == digit_strings[3]) {
            cout << digit_chars[3] << "\n";
        }
        if (input_user == digit_strings[4]) {
            cout << digit_chars[4] << "\n";
        }
        if (input_user == digit_strings[5]) {
            cout << digit_chars[5] << "\n";
        }
        if (input_user == digit_strings[6]) {
            cout << digit_chars[6] << "\n";
        }
        if (input_user == digit_strings[7]) {
            cout << digit_chars[7] << "\n";
        }
        if (input_user == digit_strings[8]) {
            cout << digit_chars[8] << "\n";
        }
        if (input_user == digit_strings[9]) {
            cout << digit_chars[9] << "\n";
        }
        // spelling - digit
        if (input_user == digit_chars[0]) {
            cout << digit_strings[0] << "\n";
        }
        if (input_user == digit_chars[1]) {
            cout << digit_strings[1] << "\n";
        }
        if (input_user == digit_chars[2]) {
            cout << digit_strings[2] << "\n";
        }
        if (input_user == digit_chars[3]) {
            cout << digit_strings[3] << "\n";
        }
        if (input_user == digit_chars[4]) {
            cout << digit_strings[4] << "\n";
        }
        if (input_user == digit_chars[5]) {
            cout << digit_strings[5] << "\n";
        }
        if (input_user == digit_chars[6]) {
            cout << digit_strings[6] << "\n";
        }
        if (input_user == digit_chars[7]) {
            cout << digit_strings[7] << "\n";
        }
        if (input_user == digit_chars[8]) {
            cout << digit_strings[8] << "\n";
        }
        if (input_user == digit_chars[9]) {
            cout << digit_strings[9] << "\n";
        }
    }
}

void simple_calc_2() {
    // vectors
    vector <string> operation {"+", "-", "*", "/"};
    vector <string> digit_strings {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector <string> digit_chars {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector <int> digit_ints {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // user inputs
    string input_1_user {}; // first char
    string input_2_user {}; // operation
    string input_3_user {}; // second char

    // operations variables
    int operand_1 {};
    int operand_2 {};
    int res {};


    cout << "This program computes basic operations like summation, extraction, multiplication and division\n"
         << "Please type only digits from 0-9 or zero-nine\n"
         << "Type the first char, the operation symbol and the second char (e.g.: '1+2' or 'one + two')\n";
    while (cin >> input_1_user >> input_2_user >> input_3_user) {
        // linking operand_1 to user input
        if (input_1_user == digit_strings[0] || input_1_user == digit_chars[0]) {
            operand_1 = digit_ints[0];
        }
        if (input_1_user == digit_strings[1] || input_1_user == digit_chars[1]) {
            operand_1 = digit_ints[1];
        }
        if (input_1_user == digit_strings[2] || input_1_user == digit_chars[2]) {
            operand_1 = digit_ints[2];
        }
        if (input_1_user == digit_strings[3] || input_1_user == digit_chars[3]) {
            operand_1 = digit_ints[3];
        }
        if (input_1_user == digit_strings[4] || input_1_user == digit_chars[4]) {
            operand_1 = digit_ints[4];
        }
        if (input_1_user == digit_strings[5] || input_1_user == digit_chars[5]) {
            operand_1 = digit_ints[5];
        }
        if (input_1_user == digit_strings[6] || input_1_user == digit_chars[6]) {
            operand_1 = digit_ints[6];
        }
        if (input_1_user == digit_strings[7] || input_1_user == digit_chars[7]) {
            operand_1 = digit_ints[7];
        }
        if (input_1_user == digit_strings[8] || input_1_user == digit_chars[8]) {
            operand_1 = digit_ints[8];
        }
        if (input_1_user == digit_strings[9] || input_1_user == digit_chars[9]) {
            operand_1 = digit_ints[9];
        }
        // linking operand_2 to user input
        if (input_3_user == digit_strings[0] || input_3_user == digit_chars[0]) {
            operand_2 = digit_ints[0];
        }
        if (input_3_user == digit_strings[1] || input_3_user == digit_chars[1]) {
            operand_2 = digit_ints[1];
        }
        if (input_3_user == digit_strings[2] || input_3_user == digit_chars[2]) {
            operand_2 = digit_ints[2];
        }
        if (input_3_user == digit_strings[3] || input_3_user == digit_chars[3]) {
            operand_2 = digit_ints[3];
        }
        if (input_3_user == digit_strings[4] || input_3_user == digit_chars[4]) {
            operand_2 = digit_ints[4];
        }
        if (input_3_user == digit_strings[5] || input_3_user == digit_chars[5]) {
            operand_2 = digit_ints[5];
        }
        if (input_3_user == digit_strings[6] || input_3_user == digit_chars[6]) {
            operand_2 = digit_ints[6];
        }
        if (input_3_user == digit_strings[7] || input_3_user == digit_chars[7]) {
            operand_2 = digit_ints[7];
        }
        if (input_3_user == digit_strings[8] || input_3_user == digit_chars[8]) {
            operand_2 = digit_ints[8];
        }
        if (input_3_user == digit_strings[9] || input_3_user == digit_chars[9]) {
            operand_2 = digit_ints[9];
        }
        // operations
        // summation
        if (input_2_user == operation[0]) {
            res = operand_1 + operand_2;
            cout << input_1_user << " + " << input_3_user << " = " << res << " \n";
        }
        // extraction
        if (input_2_user == operation[1]) {
            res = operand_1 - operand_2;
            cout << input_1_user << " - " << input_3_user << " = " << res << " \n";
        }
        // multiplication
        if (input_2_user == operation[2]) {
            res = operand_1 * operand_2;
            cout << input_1_user << " * " << input_3_user << " = " << res << " \n";
        }
        // division
        if (input_2_user == operation[3]) {
            res = operand_1 / operand_2;
            cout << input_1_user << " / " << input_3_user << " = " << res << " \n";
        }
    }
}

void chess_rice_reward() {
//    double chess_box {};
    double rice_amount {};
    for (int i = 0; i < 64; ++i) {
        rice_amount = pow(2, i);
//        cout << "Chess_box[" << i + 1 << "]" << " = " << rice_amount << " grains rice\n";
        if (rice_amount >= 1000 && rice_amount <= 1200) {
            cout << i + 1 << " chess boxes " << " required to pay at least 1.000 grains rice\n";
        }
        if (rice_amount >= 1000000 && rice_amount <= 1200000) {
            cout << i + 1 << " chess boxes " << " required to pay at least 1.000.000 grains rice\n";
        }
        if (rice_amount >= 1000000000 && rice_amount <= 1200000000) {
            cout << i + 1 << " chess boxes " << " required to pay at least 1.000.000.000 grains rice\n";
        }
    }
}

void rock_paper_scissors() {
    vector <string> string_values {"rock", "paper", "scissors"};
    vector <int> random_chars;

    // input user chars which help with randomization
    int input_user_chars_1 {};
    int input_user_chars_2 {};
    int input_user_chars_3 {};
    int input_user_chars_4 {};
    int input_user_chars_5 {}; // if you add more chars to the input, change the i counter accordingly

    char input_user {' '};
    int i {0}; // question counter, if you add more chars to the input, change the i counter accordingly

    cout << "Welcome to the 'Rock, paper, scissors' game\n";
    cout << "First, let's enter 5 values from 1-5 separated by spaces (e.g. '1 2 3 4 5')\n";
    cout << "enter | to end\n";
    cin >> input_user_chars_1 >> input_user_chars_2 >> input_user_chars_3 >> input_user_chars_4 >> input_user_chars_5;
    // conditions input_user_chars
    if (input_user_chars_1 || input_user_chars_2 || input_user_chars_3 || input_user_chars_4 || input_user_chars_5 == 1 ) {
        random_chars.push_back(1);
    }
    if (input_user_chars_1 || input_user_chars_2 || input_user_chars_3 || input_user_chars_4 || input_user_chars_5 == 2 ) {
        random_chars.push_back(0);
    }
    if (input_user_chars_1 || input_user_chars_2 || input_user_chars_3 || input_user_chars_4 || input_user_chars_5 == 3 ) {
        random_chars.push_back(2);
    }
    if (input_user_chars_1 || input_user_chars_2 || input_user_chars_3 || input_user_chars_4 || input_user_chars_5 == 4 ) {
        random_chars.push_back(2);
    }
    if (input_user_chars_1 || input_user_chars_2 || input_user_chars_3 || input_user_chars_4 || input_user_chars_5 == 5 ) {
        random_chars.push_back(1);
    }

    cout << "Thank you!\n";
    cout << "Let's go! Type r for rock, p for paper or s for scissors!\n";

    while (cin >> input_user) {
        switch (input_user) {
            case('r') : {
                cout << "You picked 'rock'!\n";
                break;
            }
            case('p') : {
                cout << "You picked 'paper'!\n";
                break;
            }
            case('s') : {
                cout << "You picked 'scissors'!\n";
                break;
            }
            default: {

            }
        }
        cout << "Computer picked " << "'" << string_values[random_chars[i]] << "'!" << " \n";
        ++i;
        if (i == 5) {
            break;
        }
    }
}

void find_all_prime_chars(){
    vector<int>Primes_list{2}; // we need at least one value to divide to at first in this case 2
    int max_char {100}; // change this char as you wish

    cout << "This program finds all the prime chars from 1 to a max input (default is 100)\n"
         << "Please enter your desired max input\n";
    cin >> max_char;
    for (int i = 3; i < max_char; ++i) { // chars from 2 - 100
        for (int j = 0; j < Primes_list.size(); ++j) {
            if (i % Primes_list[j] == 0 || i == Primes_list[Primes_list.size()-1]) {
                break;
            }
            else {
                Primes_list.push_back(i);
            }
        }
    }
    cout << "Prime chars up to: " << max_char << " are:\n";
    for (int i = 0; i < Primes_list.size(); ++i) {
        cout << Primes_list[i] << "\t";
    }
}

void find_prime_eratosthenes() {
    vector<int> values_list{};
    vector<int> crossed_out_values{};
    int max_chars{1000};
    int multiplying_index{};
    int first_n_primes {0};

    cout << "Find first n prime chars using Eratosthenes's Method\n";
    cout << "Please enter first n primes chars (starting from 2) that you want to see \n\n";

    cin >> first_n_primes;

    // creating list of chars to be checked
    for (int i = 2; i <= max_chars; ++i) {
        values_list.push_back(i);
    }
    cout << "LIST OF VALUES\n";
    for (int i = 0; i < values_list.size(); ++i) {
        cout << values_list[i] << "\t";
    }
    cout << "\n";

    // removing values from the initial list
    for (int i = 0; i < values_list.size(); ++i) {
        multiplying_index = values_list[i];
        for (int j = i + 1; j < values_list.size(); ++j) {
            if (values_list[j] % multiplying_index == 0) {
                values_list.erase(values_list.begin() + j);
            }
        }
    }

    // listing list of prime values
    cout << "LIST OF PRIME charS\n";
    for (int k = 0; k < values_list.size(); ++k) {
        cout << values_list[k] << "\t";
    }
    cout << "\n";
    // listing only first n desired prime chars
    cout << "FIRST " << first_n_primes << " PRIME charS\n";
    for (int m = 0; m < first_n_primes; ++m) {
        cout << values_list[m] << "\t";
    }
    cout << "\n";
}

void find_mode() {
    int input_user {};

    vector<int>values_list{};

    int high_score_value {};
    int high_score {};

    int current_score_value {};
    int current_score {};

    cout << "Insert a set of positive integers:\n";

    while (cin >> input_user) {
        values_list.push_back(input_user);
    }
    for (int i = 0; i < values_list.size(); ++i) {
        current_score_value = values_list[i];
        current_score = 1;
        for (int j = i + 1; j < values_list.size(); ++j) {
            if (current_score_value == values_list[j]) {
                ++current_score;
            }
        }
        // checking if the current value is repeating more than the previous one
        if (current_score > high_score) {
            high_score_value = current_score_value;
            high_score = current_score;
        }
    }
    cout << "Value '" << high_score_value << "' repeats most often (" << high_score <<") times\n";
}

void find_mode_strings() {
    string input_user {};

    vector<string>values_list{};

    string high_score_value {};
    int high_score {};
    string max_string {};
    string min_string {"sentinel"};


    string current_score_value {};
    int current_score {};



    cout << "Insert a set of strings:\n";
    cout << "Insert | to break\n";

    while (cin >> input_user) {
        values_list.push_back(input_user);
        if (input_user == "|") {
            break;
        }
    }
    // in this loop we determine which value repeats the most
    for (int i = 0; i < values_list.size(); ++i) {
        current_score_value = values_list[i];
        cout << " xxx " << current_score_value << "\n";
        current_score = 1;
        for (int j = i + 1; j < values_list.size(); ++j) {
            if (current_score_value == values_list[j]) {
                ++current_score;
            }
        }

        // conditions to find max string and min string
        if (max_string < current_score_value && current_score_value != "|") {
            max_string = current_score_value;
        }
        if (min_string > current_score_value || min_string == "sentinel") {
            min_string = current_score_value;
        }

        // checking if the current value is repeating more than the previous one
        if (current_score > high_score) {
            high_score_value = current_score_value;
            high_score = current_score;
        }
    }

    cout << "Value '" << high_score_value << "' repeats most often (" << high_score <<") times\n";
    cout << "Value '" << max_string << "' is the highest string value in the series\n";
    cout << "Value '" << min_string << "' is the lowest string value in the series\n";
}

void name_value_pairs() {

    string name;
    int value;


    vector<string>names; // name array
    vector<int>scores; // age array

    cout << "Enter a unique name and an age (eg: Radu 28, Lisa 29)\n";
    while (cin >> name >> value) {
        if (name == "NoName" && value == 0) {
            break;
        }
        names.push_back(name);
        scores.push_back(value);

        string checked_name;
        for (int i = 0; i < names.size() - 1; ++i) { //
            checked_name = name;
            if (checked_name == names[i]) {
                cout << "Name already exists in DB!\n...quitting...\n";
                break;
            }
        }
    }

    // listing K:V map
    cout << "Showing Database:\n";
    int j = {0}; // initialising scores index
    for (int i = 0 ; i < names.size(); i++) {
        cout << names[i] << ":" << scores[j] << "\n";
        ++j; // incrementing scores index too!
    }

    // checking age of input name
    cout << "\nWhose age do you want to check?\n";
    string name_age_query;
    cin >> name_age_query;
    cout << "Showing age of " << name_age_query << "\n";
    for (int i = 0; i < names.size(); ++i) {
        if (name_age_query == names[i]) {
            cout << name_age_query << ":" << scores[i];
            break;
        }
        if (i == names.size() - 1) {
            cout << "Name not found!\n";
        }
    }

    // checking all names with same input age
    cout << "\nFor what age should we check the DB?\n";
    int age_name_query;
    int counter_loop {0};
    cin >> age_name_query;
    cout << "Showing names of people who match with the age " << age_name_query << "\n";
    for (int i = 0; i < scores.size(); ++i) {
        if (age_name_query == scores[i]) {
            cout << age_name_query << ":" << names[i] << "\n" ;
            ++counter_loop;
        }
        if ( i == scores.size() - 1 && counter_loop == 0 ) {
            cout << "Nobody with that age found!\n";
            break;
        }
    }
}

// 5.6 Exceptions - Start
class Bad_area{}; // a type specifically for reporting errors from area()
// calculate area
// throw a Bad_area exception in case of a bad argument
int area (int length, int width) {
    if (length <= 0 || width <= 0) throw Bad_area{};
    return length * width;
}

int framed_area (int x, int y) {
    constexpr int frame_width = 2;
    if (x - frame_width <= 0 || y - frame_width <= 0) {
        error("non-positive area() argument called by framed_area() check if inputs are both > 2");
    } // instead of calling error we can throw an exception like Bad_area (different name though) here too!
    return area(x - frame_width, y - frame_width);
}

void f (int x, int y, int z) {
    int area1 = area(x,y);
    if (area1<0) error("non-positive area");

    int area2 = framed_area(x,z);
    if (area1<0) error("non-positive area");

    int area3 = framed_area(y,z);
    if (area1<0) error("non-positive area");
    double ratio = double(area1)/area3;
    //
    cout << "area1 \t" << area1 <<"\n";
    cout << "area2 \t" << area2 <<"\n";
    cout << "area3 \t" << area3 <<"\n";
    cout << "ratio \t" << ratio <<"\n";
}

void bad_area_catch() {
    try {

        int x = -1;
        int y = 2;
        int z = 4;
        int area1 = area(x,y);
        int area2 = framed_area(1,z);
        int area3 = framed_area(y,z);
        double ratio = area1/area3;
    }
    catch (Bad_area) {
        cout << "Oops! Bad arguments to area()\n";
    }
}
// 5.6 Exceptions - end


int drill_3 () {
    // Chapter Errors
    try {
        // Code here
//        cout << "Success! \n";
//        cout << "Success!\n";
//        cout << "Success" << "!\n";
//        cout << "Success" << "!\n";
//        cout << "Success!" << "\n";
//        int res = 7; vector < int > v( 10); v[5] = res; cout << "Success!\n";
//        vector < int > v(10); v[5] = 7; if (v[5] == 7) cout << "Success!\n";
//        vector < int > v(10); v[5] = 7; if (v[5] == 7) cout << "Success!\n"; else cout << "Fail!\n";
//        bool c = false; if (!c) cout << "Success! \n"; else cout << "Fail!\n";
//        string s = "ape"; bool c = !("fool" < s); if (c) cout  << "Success!\n";
//        string s = "ape"; if (s != "fool") cout << "Success!\n";
//        string s = "ape"; if (s != "fool") cout << "Success!\n";
//        vector <char> v(5); for (int i = 0; i < v.size(); ++i); cout << "Success!\n";
//        vector < char > v(5); for (int i = 0; i <= v.size(); ++i) {cout << i << "\t";} cout << "Success!\n";
//        string s = "Success"; for (int i = 0; i < 6; ++i) cout << s[i]; cout << "!\n";
//        if (true) cout << "Success!\n"; else cout << "Fail!\n";
//        int x = 2000; int c = x; if (c == 2000) cout << "Success!\n";
//        string s = "Success!\n"; for (int i = 0; i < 8; ++i) cout << s[i]; cout << "\n";
//        vector <int> v( 5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";
//        int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "Success!\n";
//        double x = 2; double d = (5 / (x-1) - 0.5);if (d == 2*x + 0.5) cout << "Success!\n";
//        string s = "Success!\n"; for (int i = 0; i <= 7; ++i) {cout << s[i];} cout << "\n";
//        int j = 8; int i = 0; while (i < 10) ++i; if (j < i) cout << "Success!\n";
//        double x = 4; double d = 5/ (x - 2); if (d == 2*x - 5.5) cout << "Success!\n";
        cout << "Success!\n";

        keep_window_open();
        return 0;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << "\n";
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}

// Start // 5.6 Exceptions - Celsius to Kelvin
double c_to_k (double c) {
    if (c < -273.15) {
        error("Temperatures below -273.15 C are not accepted.");
    }
    double k = c + 273.15;
    return k;
}

double k_to_c (double k) {
    if (k < 0) {
        error("Temperatures below 0 K are not accepted.");
    }
    double c = k - 273.15;
    return c;
}

void c_to_k_main() {
    char a = ' ';

    cout << "Convert Celsius to Kelvin or viceversa\n"
         << "Enter 'c' if you want to convert Celsius to Kelvin degrees\n"
         << "Enter 'k' if you want to convert Kelvin to Celsius degrees\n";

    cin >> a;

    switch (a) {
        case 'c' : {
            double c; // Celsius
            double k; // Kelvin
            cout << "Enter Celsius degrees\n";
            cin >> c;
            k = c_to_k(c);
            cout << c << "C = " << k << "K\n";
            break;
        }
        case 'k' : {
            double k; // Kelvin
            double c; // Celsius
            cout << "Enter Kelvin degrees\n";
            cin >> k;
            c = k_to_c(k);
            cout << k << "K = " << c << "C\n";
            break;
        }
        default : {}
    }
}
// End // 5.6 Exceptions - Celsius to Kelvin

// Start "Bulls and Cows"
void bulls_and_cows() {
    // This programs generates a series of 4 random digits and then prompts the user
    // how many of them he guessed in their right positions or if he guessed some at all.
    // eg. series 1234 - guess 1457 - Computer answer: You got 1(1) bull and 1(digit 4) cow(s).

    cout << "Welcome to the 'Bulls and Cows' Game\n";
    cout << "Please enter a random char:\n";

    // user inputs a random char representing the "seed" factor
    int rand_input;
    cin >> rand_input;
    seed_randint(rand_input);

    // storing random digits from 0-10 in a vector(4)
    // because the randomization algorithm can generate duplicates
    // from 0-10, the fastest option is to store in each index
    // a random char from specific intervals each

    vector <int> random_digits(4);
    random_digits[0] = randint(0,2);
    random_digits[2] = randint(8,10);
    random_digits[1] = randint(3,5);
    random_digits[3] = randint(6,7);

    // user inputs his guess
    int char_0; int char_1; int char_2; int char_3;
    cout << "Type in your guess"
            " (four distinct integers separated by spaces):"
            " eg. 1 2 3 4 \n";
    cin >> char_0 >> char_1 >> char_2 >>char_3;

    // precondition: input chars must be distinct
    vector<int>user_input_chars{char_0, char_1, char_2, char_3};
    sort (user_input_chars); // we sort to have them in order so that we can compare
    for (int i = 0; i < user_input_chars.size() - 1; ++i) {
        if (user_input_chars[i] == user_input_chars[i+1]) {
            error("User input chars must be distinct!\n");
        }
    }

    // bull counter
    int bull_counter = {0};
    int cow_counter = {0};

    if (random_digits[0] == char_0) {
        ++bull_counter;
    }
    if (random_digits[1] == char_1) {
        ++bull_counter;
    }
    if (random_digits[2] == char_2) {
        ++bull_counter;
    }
    if (random_digits[3] == char_3) {
        ++bull_counter;
    }
    // cow counter
    if (random_digits[0] == char_1 || random_digits[0] == char_2
    || random_digits[0] == char_3) {
        ++cow_counter;
    }
    if (random_digits[1] == char_0 || random_digits[1] == char_2
        || random_digits[1] == char_3) {
        ++cow_counter;
    }
    if (random_digits[2] == char_0 || random_digits[2] == char_1
        || random_digits[2] == char_3) {
        ++cow_counter;
    }
    if (random_digits[3] == char_0 || random_digits[3] == char_1
        || random_digits[3] == char_2) {
        ++cow_counter;
    }

    // Result
    cout << "char was: ";
    for (int x : random_digits) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Your guess: \n"
         << char_0 << " " << char_1 << " " << char_2 << " " << char_3 << "\n";

    cout << "You got " << bull_counter << " Bulls" << " and " << cow_counter << " Cows!\n";

}

//------------------------------------------------------------------------------

// Chapter 6. Exercise 4 -- Rework Chapter 4. Exercise 9 using a Class struct

class Name_value {
public:
    string person_name;
    int person_value;

    Name_value(string person_name, int person_value)
    :person_name(move(person_name)), person_value(person_value)
    { }
};

void name_value_pairs_reworked() {

    vector<Name_value>name_database{};

    string name;
    int value;

    cout << "Enter a unique name and value (eg: Radu 28, Lisa 29)\n";
    while (cin >> name >> value) {
        if (name == "NoName" && value == 0) {
            break;
        }
        name_database.push_back(Name_value(name, value));

        string checked_name;
        for (int i = 0; i < name_database.size() - 1; ++i) { //
            checked_name = name;
            if (checked_name == name_database[i].person_name) {
                cout << "Name already exists in DB!\n...quitting...\n";
                break;
            }
        }
    }

    // listing K:V map
    cout << "Showing Database:\n";
    for (int i = 0 ; i < name_database.size(); ++i) {
        cout << name_database[i].person_name << ":" << name_database[i].person_value << "\n";
    }

    // checking age of input name
    cout << "\nWhose age do you want to check?\n";
    string name_age_query;
    cin >> name_age_query;
    cout << "Showing age of " << name_age_query << "\n";
    for (int i = 0; i < name_database.size(); ++i) {
        if (name_age_query == name_database[i].person_name) {
            cout << name_age_query << ":" << name_database[i].person_value;
            break;
        }
        if (i == name_database.size() - 1) {
            cout << "Name not found!\n";
        }
    }

    // checking all names with same input age
    cout << "\nFor what age should we check the DB?\n";
    int age_name_query;
    int counter_loop {0};
    cin >> age_name_query;
    cout << "Showing names of people who match with the age " << age_name_query << "\n";
    for (int i = 0; i < name_database.size(); ++i) {
        if (age_name_query == name_database[i].person_value) {
            cout << age_name_query << ":" << name_database[i].person_name << "\n" ;
            ++counter_loop;
        }
        if ( i == name_database.size() - 1 && counter_loop == 0 ) {
            cout << "Nobody with that age found!\n";
            break;
        }
    }
}

//------------------------------------------------------------------------------

// Chapter 6 - Exercise 6 - checking english grammar
class Dictionary_word
    {
        public:
        string word;
        int word_value;

        Dictionary_word(string key, int val)
        :word(move(key)), word_value(val)
        {}
    };

void sentence_check() {
    // known words
    vector<string>art = {"the"}; // 1
    vector<string>noun = {"birds", "fish", "cpp"}; // 2
    vector<string>verb = {"rules", "fly", "swim"};  // 3
    vector<string>conj = {"and", "or", "but"}; // 4
    vector<string>sp_char = {"."}; // 5

    // adding words to a string vector
    // initialising Database
    vector<Dictionary_word>Database;

    // populating database with words
    // adding articles to database with value 1
    for (int i=0; i < art.size(); ++i ) {
        Database.push_back(Dictionary_word(art[i], 1));
    }
    // adding nouns to database with value 2
    for (int i=0; i < noun.size(); ++i ) {
        Database.push_back(Dictionary_word(noun[i], 2));
    }
    // adding verbs to database with value 3
    for (int i=0; i < verb.size(); ++i ) {
        Database.push_back(Dictionary_word(verb[i], 3));
    }
    // adding conjunctions to database with value 4
    for (int i=0; i < conj.size(); ++i ) {
        Database.push_back(Dictionary_word(conj[i], 4));
    }
    // adding special characters to database with value 5
    for (int i=0; i < sp_char.size(); ++i ) {
        Database.push_back(Dictionary_word(sp_char[i], 5));
    }

    // printing database
    cout << "Available words for use:\n";
    for (int i=0; i < Database.size(); ++i ) {
        cout << Database[i].word << ":" << Database[i].word_value << " ";
    }

    // define a correct small sentence
    // if 1 < 2 < 3 OK! when each doesn't repeat itself and all are present
    cout << "Make a sentence of 7 from the available words, followed by a '.'\n";
    cout << "Example: 'the dogs bark and the cats meow .'\n";
    string input_user{}; // input user
    vector<int>word_val_user; // list of word values entered by the user

    // in while loop inputs are being added
    while (cin) {
        cin >> input_user;
        if (input_user == "q") {
            break;
        }
        // Filter if word is in our db - begin
        for(int i=0; i<Database.size(); ++i) {
            if (input_user == Database[i].word) {
                cout << "check ok!\n";
                break;
            }
            // quit with error if check reaches end
            if (i == Database.size()-1) {
                error("check failed! Input is not found in the database..."
                      "try again\n");
            }
        }
        // Filter - end

        // get the corresponding value from the db for each word who passed the filter;
        for(int i=0; i<Database.size(); ++i) {
            if (input_user == Database[i].word) {
                word_val_user.push_back(Database[i].word_value);
                break;
            }
        }
    }


    // Display input word - values
    cout << "list of word values: [ ";
    for (int x: word_val_user) {
    cout << x << " ";
    }
    cout << "]\n";

    // Filter for a correct sentence - begin
    // Conditions:
    bool cond_1 (word_val_user[0] == 1);
    bool cond_2 (word_val_user[1] == 2);
    bool cond_3 (word_val_user[2] == 3);
    bool cond_4 (word_val_user[3] == 4);
    bool cond_5 (word_val_user[4] == 1);
    bool cond_6 (word_val_user[5] == 2);
    bool cond_7 (word_val_user[6] == 3);
    bool cond_8 (word_val_user[7] == 5);
    //TODO Simplest solution for a single scenario case only...
    if (cond_1 && cond_2 && cond_3 && cond_4 && cond_5 && cond_6 && cond_7 && cond_8 ) { // if conditions are true
        cout << "Sentence is correct!\n";
    }
    else {
        cout << "Sentence is missing a word or words not in right order!\n";
        cout << "Check again!\n";
    }
    // Filter for a correct sentence - end

}
// Start "Bulls and Cows - reworked"
void bulls_and_cows_reworked() {
    // This programs generates a series of 4 random digits and then prompts the user
    // how many of them he guessed in their right positions or if he guessed some at all.
    // eg. series 1234 - guess 1457 - Computer answer: You got 1(1) bull and 1(digit 4) cow(s).

    cout << "Welcome to the 'Bulls and Cows' Game\n";
    cout << "This version has been reworked to show four letters instead of digits\n";
    cout << "Please enter a random char:\n";

    // user inputs a random char representing the "seed" factor
    int rand_input;
    cin >> rand_input;
    seed_randint(rand_input);

    // storing random digits from 0-10 in a vector(4)
    // because the randomization algorithm can generate duplicates
    // from 0-10, the fastest option is to store in each index
    // a random char from specific intervals each

    vector <char> random_digits(4);
    random_digits[0] = randint(97,102); // a-f
    random_digits[2] = randint(109,115); // m - s
    random_digits[1] = randint(116,122); // t - z
    random_digits[3] = randint(103,108); // g-l
    // transforming every random char to its corresponding char


    // user inputs his guess
    char char_0; char char_1; char char_2; char char_3;
    cout << "Type in your guess!"
            " Must be four distinct (small case) letters separated by space:"
            " eg. a b c d \n";
    cin >> char_0 >> char_1 >> char_2 >>char_3;

    // precondition: input chars must be distinct
    vector<char>user_input_chars{char_0, char_1, char_2, char_3};
    sort (user_input_chars); // we sort to have them in order so that we can compare
    for (int i = 0; i < user_input_chars.size() - 1; ++i) {
        if (user_input_chars[i] == user_input_chars[i+1]) {
            error("User input chars must be distinct!\n");
        }
    }

    // bull counter
    int bull_counter = {0};
    int cow_counter = {0};

    if (random_digits[0] == char_0) {
        ++bull_counter;
    }
    if (random_digits[1] == char_1) {
        ++bull_counter;
    }
    if (random_digits[2] == char_2) {
        ++bull_counter;
    }
    if (random_digits[3] == char_3) {
        ++bull_counter;
    }
    // cow counter
    if (random_digits[0] == char_1 || random_digits[0] == char_2
        || random_digits[0] == char_3) {
        ++cow_counter;
    }
    if (random_digits[1] == char_0 || random_digits[1] == char_2
        || random_digits[1] == char_3) {
        ++cow_counter;
    }
    if (random_digits[2] == char_0 || random_digits[2] == char_1
        || random_digits[2] == char_3) {
        ++cow_counter;
    }
    if (random_digits[3] == char_0 || random_digits[3] == char_1
        || random_digits[3] == char_2) {
        ++cow_counter;
    }

    // Result
    cout << "char was: ";
    for (char x : random_digits) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Your guess: \n"
         << char_0 << " " << char_1 << " " << char_2 << " " << char_3 << "\n";

    cout << "You got " << bull_counter << " Bulls" << " and " << cow_counter << " Cows!\n";
}
//------------------------------------------------------------------------------

// Start "digits to integers"

class Digits_integers {
public:
    char int_names; // user input char
    int int_values; // corresponding integer value for the name
    Digits_integers(char key, int val)
    :int_names(key), int_values(val)
    {}

};

void digits_to_integers() {
    vector<char>char_list; // values from user input come here
    char input_char;

    // adding user chars to the char_list
    cout << "Enter a char (maximum 4-digits). eg:'1234'\n";
    cout << "Enter 'x' to end \n";
    while (cin) {
        cin >> input_char;

        if (input_char == 'x') {
            cout << "loop end: end by user.\n";
            break;
        }
        if (char_list.size() < 4) {
            char_list.push_back(input_char);
        }
        else {
            cout << "loop end: list full.\n";
            break;
        }
    }

    // showing values in char_list
    cout << "---Displaying char_list---\n";
    for (char x : char_list) {
        cout << x << " ";
    }
    cout << "\n";

    // creating array with corresponding values for the names
    // values: // 0 = thousands // 1 = hundreds // 2 = tens // 3 = ones
    vector<int>c_values{0,1,2,3};

    // declaring map of key-values pairs
    vector<Digits_integers>char_list_c_values;

    // mapping char_list with c_values
    int j = 3; // iterator for c_values where 3 = ones, last value from series is first picked
    for (int i = char_list.size()-1; i > -1; --i) {
        char_list_c_values.push_back(Digits_integers(char_list[i], c_values[j]));
        --j;
    }

    // display map char_list_c_values
    cout << "---Displaying map---\n";
    for (int i = char_list_c_values.size()-1; i > -1; --i) {
        cout << char_list_c_values[i].int_names << ":" << char_list_c_values[i].int_values << " ";
    }
    cout << "\n";

    // display output
    cout << "---Displaying output result---\n";
    // first value eg. '123'
    for (int i = char_list_c_values.size()-1; i > -1; --i) {
        cout << char_list_c_values[i].int_names;
    }
    cout << " is ";
    string translation_int_string;
    for (int i = char_list_c_values.size()-1; i > -1; --i) {
        // names to match
        // values: // 0 = thousands // 1 = hundreds // 2 = tens // 3 = ones
        if (char_list_c_values[i].int_values == 3) {
            translation_int_string = "ones";
        }
        if (char_list_c_values[i].int_values == 2) {
            translation_int_string = "tens";
        }
        if (char_list_c_values[i].int_values == 1) {
            translation_int_string = "hundreds";
        }
        if (char_list_c_values[i].int_values == 0) {
            translation_int_string = "thousands";
        }
        cout << char_list_c_values[i].int_names << " " << translation_int_string << " ";
    }
}
// End "digits to integers"
// TODO Could add error checking for max input = 4 and non-digit chars

//------------------------------------------------------------------------------

// Start "combinations or permutations"

double factorial(double x) {
    // precondition
    if (x<0) {
        error("Factorial is defined only for non-negative integer chars");
    }
    if ((x==0)||(x==1)) {
        return 1;
    }
    else {
        return x * factorial(x - 1);
    }
}

double do_permutations (double a, double b) {
    // ordered subset of a set
    double ret = factorial(a) / factorial(a-b);
    return ret;
}

double do_combinations (double a, double b) {
    // ordered subset of a set
    double ret = do_permutations(a, b) / factorial(b);
    return ret;
}

void permutations_or_combinations() {
    cout << "Please type in 2 integer numbers"
            "where a > b\n";
    double a;
    double b;
    cin >> a >> b;
    cout << "Type 'p' to compute number of permutations or\n";
    cout << "Type 'c' to compute number of combinations\n";
    char pc;
    cin >> pc;
    switch (pc) {
        case 'p': {
            double ret = do_permutations(a,b);

            cout << "Permutations of " << "(" << a << ", " << b << ")"
            << " = " << ret;
            break;
        }
        case 'c': {
            double ret = do_combinations(a,b);

            cout << "Combinations of " << "(" << a << ", " << b << ")"
            << " = " << ret;
            break;
        }
        default: {
            cout << "invalid input. aborting...\n";
        }
    }
}
// TODO write errors for all possible bad user inputs
// End "combinations or permutations"
//------------------------------------------------------------------------------

