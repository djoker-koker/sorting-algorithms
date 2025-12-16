#ifndef CATCH_HPP
#define CATCH_HPP

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_FAST_COMPILE

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

namespace Catch {
    class Session {
        struct TestCase {
            std::string name;
            std::string tags;
            void (*func)();
        };
        static Session* s_instance;
        std::vector<TestCase> m_tests;
        int m_failed;
        
    public:
        Session() : m_failed(0) { s_instance = this; }
        
        static Session& getInstance() { 
            if (!s_instance) s_instance = new Session();
            return *s_instance; 
        }
        
        void addTest(const char* name, const char* tags, void (*func)()) {
            m_tests.push_back({name, tags, func});
        }
        
        int run(int argc = 0, char* argv[] = nullptr) {
            (void)argc; (void)argv;
            int passed = 0;
            std::cout << "Запуск тестов...\n\n";
            
            for (auto& test : m_tests) {
                std::cout << test.name << " ... ";
                try {
                    test.func();
                    std::cout << "ПРОЙДЕН\n";
                    passed++;
                } catch (const char* msg) {
                    std::cout << "ОШИБКА: " << msg << "\n";
                    m_failed++;
                } catch (...) {
                    std::cout << "ОШИБКА\n";
                    m_failed++;
                }
            }
            
            std::cout << "\n====================\n";
            std::cout << passed << " пройдено, " << m_failed << " не пройдено\n";
            return m_failed > 0 ? 1 : 0;
        }
    };
    
    Session* Session::s_instance = nullptr;
}

#define TEST_CASE(name, tags) \
    void INTERNAL_CATCH_UNIQUE_NAME(test_func)(); \
    namespace { \
        struct INTERNAL_CATCH_UNIQUE_NAME(test_reg) { \
            INTERNAL_CATCH_UNIQUE_NAME(test_reg)() { \
                Catch::Session::getInstance().addTest(name, tags, INTERNAL_CATCH_UNIQUE_NAME(test_func)); \
            } \
        } INTERNAL_CATCH_UNIQUE_NAME(test_reg_instance); \
    } \
    void INTERNAL_CATCH_UNIQUE_NAME(test_func)()

#define INTERNAL_CATCH_UNIQUE_NAME_LINE2(name, line) name##line
#define INTERNAL_CATCH_UNIQUE_NAME_LINE(name, line) INTERNAL_CATCH_UNIQUE_NAME_LINE2(name, line)
#define INTERNAL_CATCH_UNIQUE_NAME(name) INTERNAL_CATCH_UNIQUE_NAME_LINE(name, __LINE__)

#define REQUIRE(expr) \
    do { \
        if (!(expr)) { \
            throw "Тест не пройден: " #expr; \
        } \
    } while(0)

#endif // CATCH_HPP
