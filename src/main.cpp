#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>
#include<stack>

using namespace std;

namespace Util{
    /** @brief The array of the strings. */
    using StrVec = std::vector<std::string>;

    /**
     * @brief Separate the strings.
     * @param text The string you want to separate.
     * @param delim The delim string. ( def: " " )
     * @return The object of the std::Vector for std::string, which was separated.
    */
    StrVec split( const std::string& text, const std::string& delim = std::string(" ") ){
        StrVec res;
        int end = 0, begin = 0, n = 0;
        while( true ){
            end   = text.find( delim, begin );
            if( end == std::string::npos ){
                res.push_back( text.substr( begin, (text.size() - begin) ) );
                break;
            }
            n = (end - begin);
            res.push_back( text.substr( begin, n ) );
            begin = end + 1;
        }
    return res;
    }

    /**
     * @brief Convert the data to the string.
     * @param val The data you want to convert.
     * @return The string which was converted from the data.
     */
    template<typename T> std::string ToString( T val ){
        std::stringstream ss;
        ss << val << flush;
    return ss.str();
    }
}

namespace Original{
    std::vector<int> CalcScalarMultiple( const std::vector<int>& orig, int scalar ){
        std::vector<int> res(orig.size());
        for( int i = 0; i < static_cast<int>(orig.size()); i++ ){
            res[i] = orig[i] * scalar;
        }
    return res;
    }

    std::vector<int> AddColumnVector( const std::vector<int>& v1, const std::vector<int>& v2 ){
        std::vector<int> res(v1.size());
        for( int i = 0; i < static_cast<int>(v1.size()); i++ ){
            res[i] = v1[i] + v2[i];
        }
    return res;
    }
}

namespace Original{
    class Person{
        public:
            Person( const std::string& name, int point ) : name_(name),point_(point){}
            ~Person() = default;

            bool IsGreaterThan( const Person* p ){
                if( this->point_ > p->point_ ) return true;
            return false;
            }

            Person* Clone( void ) const{
                return new Person( this->name_, this->point_ );
            }

            std::string ToString( void ) const{
                std::stringstream ss;
                ss << this->name_ << " " << this->point_;
            return ss.str();
            }
        private:
            std::string name_;
            int point_;
    };

    class PersonManager{
        public:
            PersonManager() : persons_(std::vector<Person*>()){}
            ~PersonManager(){
                for( int i = 0; i < static_cast<int>(persons_.size()); i++ ){
                    if( persons_[i] ) delete persons_[i];
                }
            }

            void Add( Person* person ){
                this->persons_.push_back( person );
            }

            Person* CalcMaxPerson(){
                int pos = 0;
                for( int i = 1; i < static_cast<int>(persons_.size()); i++ ){
                    if( persons_.at( i ) == nullptr ) continue;

                    if( persons_[i]->IsGreaterThan( persons_[pos] ) ){
                        pos = i;
                    }
                }
                auto res = persons_[pos]->Clone();
                delete persons_[pos];
                persons_[pos] = nullptr;
            return res;
            }
        private:
            std::vector<Person*> persons_;
    };
}

int main( int argc, char** argv ){
    int m, n;
    cin >> m >> n;

    Original::PersonManager manager;
    for( int i = 0; i < m; i++ ){
        std::string name;
        int point;
        cin >> name >> point;
        manager.Add( new Original::Person( name, point ) );
    }

    Original::Person* resPerson;
    for( int i = 0; i < n; i++ ){
        resPerson = manager.CalcMaxPerson();
    }

    cout << resPerson->ToString() << endl;

return 0;
}
