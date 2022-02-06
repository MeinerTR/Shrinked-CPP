#include <iostream>
#include <string>
#include <fstream>
#include <list>

int LINE = 0;

bool Check(int MODE, std::string CHECK, std::string THAT)
{
    if (MODE == 1)
    {
        if (CHECK[THAT.length() + 1] != '\0')
        {
            return false;
        }
        for (int x = 0; x < THAT.length(); x++)
        {
            if (CHECK[x] == THAT[x]){} else
            {
                return false;
            }
        } return true;
    }
    else
    {
        if (CHECK[CHECK.length() - THAT.length() - 1] != '\0')
        {
            return false;
        }
        for (int x = (CHECK.length() - THAT.length()); x < CHECK.length(); x++)
        {
            if (CHECK[x] == THAT[x - (CHECK.length() - THAT.length())]){} else
            {
                return false;
            }
        } return true;
    }
}

int CheckCurrent(std::string Line)
{
    if (Check(1, Line, "inc"))
    {
        return 0;
    }
    else if (Check(1, Line, "fun"))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

std::string Spaced(std::string STR)
{
    std::string sTr = "     " + STR;
    return sTr;
}

std::list<std::string> Split(std::string STR, char CHR)
{
    bool OK = 0;
    bool Brackets = 0;
    bool Parantheses = 0;
    std::string CurrLetter;
    std::list<std::string> Output;
    for (int i = 0; i < STR.length(); i++)
    {
        if (STR.length() > 0)
        {
            char cHr = STR[i];
            if (cHr == '(')
            {
                Parantheses = 1;
            }
            if (Parantheses)
            {
                if (cHr == '[')
                {
                    CurrLetter += "ar";
                    Brackets = 1;
                }
                else if (Brackets)
                {
                    if (cHr == '*')
                    {
                        OK = 1;
                    }
                    else
                    {
                        if (cHr == ']')
                        {
                            if (OK)
                            {
                                CurrLetter += "**";
                            }
                            else
                            {

                            }
                            Brackets = 0;
                        }
                    }
                }
                else
                {
                    CurrLetter += cHr;
                    if (cHr == ')')
                    {
                       Output.push_back(CurrLetter);
                       CurrLetter = "";
                       Parantheses = 0;
                    }
                }
            }
            else
            {
                if (cHr == CHR)
                {
                    Output.push_back(CurrLetter);
                    CurrLetter = "";
                }
                else if (cHr == '\n')
                {
                    Output.push_back(CurrLetter);
                    CurrLetter = "";
                }
                else if (i == STR.length() - 1)
                {
                    Output.push_back(CurrLetter);
                    CurrLetter = "";
                }
                else
                {
                    CurrLetter += cHr;
                }
            }
        }
    }
    return Output;
}

int main(int argc, char *argv[])
{
    std::string Output;
    std::string FilePath = argv[1];
    std::ifstream FILE0(FilePath.c_str());
    std::string input((std::istreambuf_iterator<char>(FILE0)),
                      (std::istreambuf_iterator<char>())); 
    FILE0.close();

    std::list<std::string> Input = Split(input, ' ');

    int CurrPos = 0;
    int Current = -1;
    int Currently = 0;
    std::string _Line;
    for (auto Line : Input)
    {
        LINE++;
        std::cout << Line << std::endl;
        if (Current == 0)
        {
            if (Currently == 0)
            {
                _Line = "#include ";
            }
            else
            {
                _Line = Spaced("#include "); 
            }
            _Line += '<';
            _Line += Line;
            _Line += ">\n";
            Output += _Line;
            Current = -1;
        }
        else if (Current == 1)
        {
            if (Currently == 0)
            {
                _Line = "int ";
            }
            else
            {
                _Line = Spaced("int "); 
            }
            _Line += Line;
            Current = 2;
        }
        else if (Current == 2)
        {
            _Line += Line;
            Output += _Line;
            if (Currently == 0)
            {
                _Line = "{";
            }
            else
            {
                _Line = Spaced("{"); 
            }
            Output += _Line;
            Currently = 5;
            Current = -1;
        }
        else
        {
            Current = CheckCurrent(Line);
        }
    }
    FilePath.erase(FilePath.end()-4, FilePath.end());
    FilePath += "cpp";
    std::ofstream FILE1(FilePath.c_str());
    FILE1 << Output;
    FILE1.close();
    return 0;
}