# 1. Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++20 \
           -IApp/include \
           -IBanking_System/include \
           -IOnline_MarketPlace/include

# 2. Target Name
TARGET = system_app

# 3. Detect OS for cleaning (Cross-Platform Logic)
ifeq ($(OS),Windows_NT)
    # Windows-specific: Use cmd to call 'del'
    CLEAN_CMD = cmd /C del /Q $(TARGET).exe
    EXECUTABLE = $(TARGET).exe
else
    # Linux/Mac-specific: Use standard 'rm'
    CLEAN_CMD = rm -f $(TARGET)
    EXECUTABLE = $(TARGET)
endif

# 4. List of all source files
SRCS = App/src/main.cpp \
       App/src/SystemApp.cpp \
       Banking_System/src/Bank.cpp \
       Banking_System/src/BankAccount.cpp \
       Banking_System/src/CheckingAccount.cpp \
       Banking_System/src/SavingsAccount.cpp \
       Online_MarketPlace/src/Cart.cpp \
       Online_MarketPlace/src/OnlineMarketplace.cpp \
       Online_MarketPlace/src/Product.cpp \
       Online_MarketPlace/src/User.cpp

# 5. Build Rules
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXECUTABLE)

clean:
	$(CLEAN_CMD)