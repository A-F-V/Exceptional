#include <memory>
namespace afv {

template <typename Value, typename ExceptionBase> class exceptional {
    public:
    exceptional (Value&& val)
    : value{ std::make_unique<Value> (std::forward<Value> (val)) }, exception{}, failed{ false } {
    }

    exceptional (ExceptionBase&& exc)
    : value{}, exception{ std::make_unique<ExceptionBase> (std::forward<ExceptionBase> (exc)) }, failed{ true } {
    }

    template <typename Return, typename F>
    exceptional<Return, ExceptionBase> and_then (F&& f) {
        if (!failed) {
            return exceptional<Return, ExceptionBase> (f (std::move (*value)));
        }
        return exceptional<Return, ExceptionBase> (*exception);
    };

    template <typename F> void and_finally (F&& f) {
        if (!failed) {
            f (std::move (*value));
        }
    }

    private:
    bool failed;
    std::unique_ptr<Value> value;
    std::unique_ptr<ExceptionBase> exception;
};

} // namespace afv