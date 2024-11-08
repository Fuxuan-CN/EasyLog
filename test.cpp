#include "Logging/logging.h"

int main() {
    Formatter mylogFormatter("{time} | {level:<7} | {file}:{function}:{line:<2} | {message}");
    Logger& logger = LogManager::getLogger("test", LogLevel::LevelTRACE, mylogFormatter);

    // 使用 HandlerFactory 创建 StreamHandler
    auto consoleHandler = HandlerFactory::createStreamHandler("console", LogLevel::LevelTRACE, mylogFormatter, std::cout, true);
    logger.addHandler(std::move(consoleHandler));

    logger.trace("trace message", __FILE__, __FUNCTION__, __LINE__);
    return 0;
}