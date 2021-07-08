class Button {
    private:
        bool state;
        unsigned char pin;

    public:
        Button(unsigned char pin) : pin(pin) {}

        void begin() {
            pinMode(pin, INPUT_PULLUP);
            state = digitalRead(pin);
        }

        bool isReleased() {
            bool read = digitalRead(pin);
            if (read != state) {
                state = read;
                if (state) {
                    return true;
                }
            }
            return false;
        }
};