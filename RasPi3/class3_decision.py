
STOP_CLASS = "person"
RUN_CLASS = "chair"

def decide_pwm(detected_classes):
    classes = set(detected_classes)

    if STOP_CLASS in classes:
        return 0

    if RUN_CLASS in classes:
        return 180

    return 120


if __name__ == "__main__":
    test_cases = [
        ["person"],
        ["chair"],
        ["person", "chair"],
        []
    ]

    for classes in test_cases:
        print(f"Detected: {classes} -> PWM: {decide_pwm(classes)}")
