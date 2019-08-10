use std::fmt;

pub struct TestCase {
    input_title: String,
    output_title: String,
    input: String,
    output: String,
}

impl TestCase {
    pub fn new(input_title: String, output_title: String, input: String, output: String) -> TestCase {
        let mut processed_input = input;
        let mut processed_output = output;
        if processed_input.ends_with("\n") {
            processed_input.pop();
        }
        if processed_output.ends_with("\n") {
            processed_output.pop();
        }
        TestCase {
            input_title: input_title,
            output_title: output_title,
            input: processed_input,
            output: processed_output,
        }
    }
}

impl fmt::Display for TestCase {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{} => {}",
               self.input,
               self.output,
        )
    }
}

impl fmt::Debug for TestCase {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}: {} => {}: {}",
               self.input_title,
               self.input,
               self.output_title,
               self.output,
        )
    }
}
