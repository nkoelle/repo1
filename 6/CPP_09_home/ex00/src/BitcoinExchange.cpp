#include "../inc/BitcoinExchange.hpp"

//**Con- & Destructor**//
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) 
{
    *this = obj;
}

BitcoinExchange::~BitcoinExchange(){}

//**Operator**//


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) 
{
    if (this != &obj) 
        *this = obj;
    return *this;
}

//**Getter**//
std::map<std::string, float> &   BitcoinExchange::get_er()
{
    return (this->_ExchangeRate);
}

//**Setter**//
void   BitcoinExchange::set_map(std::string key, float value)
{
    _ExchangeRate.insert(std::make_pair(key, value));
}

//**member functions**//
std::map<std::string, float>::iterator  BitcoinExchange::find_closest_date(std::string date)
{
    std::map<std::string, float>::iterator it;

    it = _ExchangeRate.lower_bound(date);
    if (it == _ExchangeRate.begin())
        return (it);
    it--;
    return (it);
}

void    BitcoinExchange::load_csv_to_map()
{
    std::ifstream data("src/data.csv");
    float         float_value = 0;
    std::string   line;
    std::string   line1;
    std::string   line2;
    size_t        pos = 10;

    if (!data.is_open())
        std::cout << "Error while opening the data.csv file." << std::endl;
    while (std::getline(data, line))
    {
        if (pos != std::string::npos) 
        {
            line1 = line.substr(0, pos);
            line2 = line.substr(pos + 1 , '\n');
        }
        float_value = str_to_float(line2);
        set_map(line1, float_value);
    }
    data.close();
}

void        BitcoinExchange::comp_map_input(std::string input)
{

    std::string                            content;
    std::ifstream                          in(get_filepath(input));
    std::string                            date;
    std::string                            amount;
    int                                    pos;
    float                                  result = 0;
    std::map<std::string, float>::iterator it;

    if (!in.is_open())
        std::cout << "Error: could not open input file." << std::endl;
    while(!in.eof())
    {
        std::getline(in, content, '\n');
        if (content == ("date | value"))
            continue;
        pos = 0;
        pos = content.find("|", pos);
        if (pos == 0)
        {
            std::cout << "Error: no delimiter" << std::endl;
            continue;
        }
        if (pos != 11)
        {
            std::cout << "Error: date not in format YYYY-MM-DD or date is invalid" << std::endl;
            continue;
        }
        date = content.substr(0, pos - 1);
        amount = content.substr(pos + 2 , content.length());
        if (amount.empty() || amount.size() > std::numeric_limits<float>::digits10 + 2 || amount[0] == '-')
        {
            std::cout << "Error: amount not valid" << std::endl;
            continue;
        }
        if (check_valid_date(date) == false)
        {
            std::cout << "Error: date not in format YYYY-MM-DD or date is invalid" << std::endl;
            continue;
        }
        it = _ExchangeRate.find(date);
        if (it == _ExchangeRate.end())
            it = find_closest_date(date);
        result = (it->second * std::atoi(amount.c_str()));
        std::cout << date << " | " << result << std::endl;
    }
    in.close();
}

//** helper functions**//
bool       BitcoinExchange::check_valid_date(std::string s)
{
  std::tm tm = {};

  if (!strptime(s.c_str(), "%Y-%m-%d", &tm)) 
    return false;
  return true;
}

float       BitcoinExchange::str_to_float(std::string& s)
{
    float   f_value = 0;

    if ((f_value = std::atof(s.c_str())) == 0.0)
        return static_cast<float>(std::atof(s.c_str()));
    return f_value;
}

std::string BitcoinExchange::get_filepath(std::string& s)
{
    std::string     filepath = ("src/");

    filepath += s;

    return (filepath);
}
