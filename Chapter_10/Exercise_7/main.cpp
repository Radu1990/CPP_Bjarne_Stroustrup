
/*
	calculator08buggy.cpp
*/

/*
    Simple calculator

    Revision history:
        Revised by Radu              May 2019
        Revised by Radu              April 2019
        Revised by Radu              April 2019
        Revised by Bjarne Stroustrup May 2007
        Revised by Bjarne Stroustrup August 2006
        Revised by Bjarne Stroustrup August 2004
        Originally written by Bjarne Stroustrup
            (bs@cs.tamu.edu) Spring 2004.

    This program implements a basic expression calculator.
    Input from cin; output to cout.

    This version accepts Roman numerals instead of Arabic numerals as-well

    The grammar for input is:

    Calculation:
        Statement
        Sequences of Statements
        Print
        Quit
        Calculation Statement

    Statement:
        Declaration
        Reassignment
        Expression

    Declaration:
        "let" Name "=" Expression
    Reassignment:
        "let" Name "=" Expression
    Declaration:
        "let" "const" Name "=" Expression
    Print:
        "enter"
    Help:
        "help"
    Quit:
        "quit"

    Expression:
        Term
        Expression + Term
        Expression - Term
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary
    Primary:
        Number
        Name
        ! Expression (square root of x)
        @ Raise to Power (x at power y)
        { Expression }
        ( Expression )
        - Primary
        + Primary
    Number:
        floating-point-literal


        Input comes from cin through the Token_stream called ts.
*/

//------------------------------------------------------------------------------
#include "std_lib_facilities.h"
//------------------------------------------------------------------------------
// Help Message displayed when typing help;
string h_msg = "+======================================+\n"
               "||    Help page for 'CPP BUGGY v1'    ||\n"
               "+======================================+\n"
                  "\t> type 'quit' to quit\n"
                  "\t> press enter to print result\n"
                  "\t> for square root press '! x' where x is the number\n"
                  "\t> -------------------------------------------------------------------\n"
                  "\t> for raise to power type '@ x y' where 'x' is the number;\n"
                  "\t> and 'y' is the power being raised at;\n"
                  "\t> to create a named value use 'let name value';\n"
                  "\t> -------------------------------------------------------------------\n"
                  "\t> to create a named constant value use 'let const name value';\n"
                  "\t> to reassign a value to a non-constant use '= name = new_value';\n"
                  "\t> -------------------------------------------------------------------\n";
//------------------------------------------------------------------------------
// Welcome Message display at the beginning
string w_msg = "+======================================+\n"
               "||      Welcome to 'CPP BUGGY v1'     ||\n"
               "||    if you need help type 'help'    ||\n"
               "+======================================+\n";

//------------------------------------------------------------------------------
// declaring named constant characters
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = '!';
const char raise_to_power = '@';
const char reassignment_decl = '=';
const char let = '#';
const char make_const = '&';
const char help = '!';
// declaring roman numerals

vector<string> roman_numerals {
        "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"
};
vector<double> arabic_numerals {
        1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0
};

double convert_roman_to_arabic (const string& s) {
    for (int i = 0; i<roman_numerals.size(); ++i) {
        if (roman_numerals[i] == s) {
            return arabic_numerals[i];
        }
    }
    error("No value found");

}

const string prompt = "> ";
const string result = "= ";

// Token object
struct Token {
public:
	char kind;
	double value;
	string name;
	explicit Token(char ch) :kind(ch), value(0) { } // Token with only a char
	Token(char ch, double val) :kind(ch), value(val) { } // Token with a char and a value
	Token(char ch, string n) :kind(ch), name(n) { } // Token with a char and a name
};

// creates an object of type Token_stream where we pull in the Token objects
struct Token_stream {
public:
	Token_stream() :full(false), buffer(0) { } // inits a Token stream
	Token_stream(istream&);
	Token get(); // fetches a token from the Token stream
	void unget(Token t) { full=true; buffer=t; } // puts Token back to the stream
	void ignore(char); // ignores characters of some type if found in the stream
private:
    bool full;
	Token buffer;
};
//---------------------------------------------------------------------------
Token_stream ts;
//---------------------------------------------------------------------------
Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer; // if buffer is full, empty buffer and return value from buffer
    }

    char ch;
    cin.get(ch); // note that cin.get() does NOT skip whitespace

    while (isspace(ch)) {
        if (ch == '\n') {
            return Token(print); // if newline detected, return print Token
        }
        cin.get(ch);
    }

    // cases dealing with character symbols
    switch (ch) {
        case '{':
        case '}':
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case ';':
        case '@': // raise to power
        case '=': { // used to change values defined with let
            return Token(ch);
        }
            // cases dealing with numbers
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
            cin.unget();
            double val;
            cin >> val; // write the number into a double
            return Token(number, val);
        }

        default: {
            if (isupper(ch)) {
                string r;
                r += ch;
                while (cin.get(ch) && (isupper(ch))) {
                    r += ch;
                }
                return Token(number, convert_roman_to_arabic(r));
                // TODO Continue from here
            }
            // read a sequence of chars
            if (isalpha(ch)) {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) {
                    s += ch;
                }
                if (s == "let") {
                    return Token(let);
                }
                if (s == "const") {
                    return Token(make_const);
                }
                if (s == "help") {
                    return Token(help);
                }
                if (s == "quit") {
                    return Token(quit);
                }
                return Token(name, s);
            }
            error("Bad token");
        }
    }
}
//---------------------------------------------------------------------------
void Token_stream::ignore(char c) {
	if (full && c == buffer.kind) {

		full = false; // I guess this is not useful
		unget(buffer);
	}
	full = false;
	char ch;
	while (cin >> ch) {

		if (ch==c) {
            return;
        }
	}
}
//---------------------------------------------------------------------------
class Variable {
public:
	string name;
	double value;
	bool kind; // if true == const
	Variable(string n, double v, bool k) :name(n), value(v), kind(k) { }
};
//---------------------------------------------------------------------------
class Symbol_table {
public:

    Symbol_table() = default;

    vector<Variable>var_table;

    void predefine(); // predefine value in Symbol Table
    double get(string s); // get value from Symbol Table
    void set(string s, double d, bool k); // set value in Symbol Table
    double declare(); // declare a new value in ST
    double reassignment(); // reassign value to already declared element in ST
    bool is_declared(string s); // check if value is already declared in ST
    bool declared_is_const(string s);
};
//---------------------------------------------------------------------------
Symbol_table st; // here we create an instance of the class
//---------------------------------------------------------------------------
double Symbol_table:: get(string s) {
    for (int i = 0; i < var_table.size(); ++i) {
        if (var_table[i].name == s) {
            return var_table[i].value;
        }
    }
    error("get: undefined name ",s);
}
//---------------------------------------------------------------------------
void Symbol_table:: set(string s, double d, bool k)
{
    for (int i = 0; i < var_table.size(); ++i) {
        if (var_table[i].name == s) {
            var_table[i].value = d;
            var_table[i].kind = k;
            return;
        }
    }
    error("set: undefined name ",s);
}
//---------------------------------------------------------------------------
bool Symbol_table:: is_declared(string s) {
    for (int i = 0; i<var_table.size(); ++i) {
        if (var_table[i].name == s) return true;
    }
    return false;
}
//---------------------------------------------------------------------------
bool Symbol_table:: declared_is_const(string s) {
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s && var_table[i].kind == true) return true;
    return false;
}
//---------------------------------------------------------------------------
double expression(Token_stream& ts);
//---------------------------------------------------------------------------
double Symbol_table:: declare() {
    Token t0 = ts.get();
    // try to define a named constant value
    if (t0.kind == make_const) {
        Token t1 = ts.get();
        if (t1.kind != name) error ("name expected in declaration");
        string name_declared = t1.name;
        if (is_declared(name_declared)) error(name_declared, " declared twice");
        Token t2 = ts.get();
        if (t2.kind != '=') error("= missing in declaration of " ,name);
        double d = expression(ts);
        var_table.push_back(Variable(name_declared, d, true)); // add a constant value
        return d;
    }
    // try to define a named variable
    if (t0.kind != make_const) {
        if (t0.kind != name) error ("name expected in declaration");
        string name_declared = t0.name;
        if (is_declared(name_declared)) error(name_declared, " declared twice");
        Token t1 = ts.get();
        if (t1.kind != '=') error("= missing in declaration of " ,name);
        double d = expression(ts);
        var_table.push_back(Variable(name_declared, d, false)); // add a variable value
        return d;
    }
}
//---------------------------------------------------------------------------

double Symbol_table:: reassignment() {

    Token t = ts.get();
    if (t.kind != name) error ("name expected in declaration");
    string name_declared = t.name;

    // if not declared, call error
    if (!is_declared(name_declared)) {
        error("named variable doesn't exist!");
    }
    // if declared change value
    if (is_declared(name_declared)) {
        // if declares is a const value
        if (declared_is_const(name_declared)) {
            error("can not change constant value ", name_declared);
        }
        // if declared is not a const value
        if (!declared_is_const(name_declared)) {
            Token t2 = ts.get();
            if (t2.kind != '=') error("= missing in declaration of " ,name);
            double d = expression(ts);
            set(name_declared, d, false);
            return d;
        }
    }
}

//---------------------------------------------------------------------------
void Symbol_table::predefine() {
    Variable k("k", 0, false);
    Variable pi("pi", 3.14734126318, true);
    var_table.push_back(k);
    var_table.push_back(pi);
}
//---------------------------------------------------------------------------

double primary(Token_stream& ts) {
	Token t = ts.get();
	switch (t.kind) {
	    case raise_to_power : { // raise x to the power i
	        double x = primary(ts);
	        double i = primary(ts);
            narrow_cast<int>(i);
            double ret = pow(x,i);
            return ret;
	    }
	    case square_root : {
	        double s;
	        double d = expression(ts);
            if (d > 0) {
                s = sqrt(d);
                return s;
            }
            else {
                error("Square root of non-positive numbers!");
                break;
            }
	    }
	    case '(': {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case '{': {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != '}') error("'}' expected");
            return d;
        }
        case '+': {
            return primary(ts);
        }
        case '-': {
            return - primary(ts);
        }
        case number: {
            return t.value;
        }
        case name: {
            return st.get(t.name);
        }
        default: {
            error("primary expected");
        }
	}
}

double term(Token_stream& ts) {
    double left = primary(ts);
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
            case '*': {
                left *= primary(ts);
                break;
            }
            case '/': {
                double d = primary(ts);
                if (d == 0) {
                    error("divide by zero");
                }
                left /= d;
                break;
            }
            default: {
                ts.unget(t);
                return left;
            }
        }
    }
}

double expression(Token_stream& ts) {

	double left = term(ts);
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term(ts);
			break;
		case '-':
			left -= term(ts);
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double statement() {
	Token t = ts.get();
	switch(t.kind) {
	    case reassignment_decl : {
             return st.reassignment(); // = x = y; means reassign value y to x
	    }
	    case let: {
		    return st.declare(); // # x = y; means declare var x = y;
	    }
        default: {
            ts.unget(t);
            return expression(ts); // just do the math
        }
	}
}

void clean_up_mess() {

	ts.ignore(print);
}

void calculate() {
    while (true) {
        try {
            // predefine named variables - start
            st.predefine();
            // predefine - end
            cout << prompt;
            Token t = ts.get(); // feed 1 token
            // first discard all prints
            while (t.kind == print) {
                t = ts.get();
            }
            // help
            if (t.kind == help) {
                cout << h_msg; // this displays help message
                continue;
            }
            // quit
            if (t.kind == quit) {
                return;
            }
            ts.unget(t); // put back if not ';' or 'q' or 'h'
            // if filters are passed call statement
            cout << result << statement() << endl; // as soon as unknown characters are feeded it returns the result
        }
        catch (runtime_error &e) {
            cerr << e.what() << endl;
            clean_up_mess();
        }
    }
}

int main() {
    try {
        cout << w_msg; // display welcome message help
        calculate();
        return 0;
    }
    catch (exception &e) {
        cerr << "exception: " << e.what() << endl;
        char c;
        while (cin >> c && c != ';');
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        char c;
        while (cin >> c && c != ';');
        return 2;
    }
}
