use std::fs::File;
use std::io::Read;

// holy shit the joke program became useful

fn main() {
    /*let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        error_operation();
        return;
    }*/
    parse_challenge();
    return;
}
fn parse_challenge() {
    let mut file = File::open("test.txt").expect("error: file not found");
    let mut contents = String::new();
    file.read_to_string(&mut contents).expect("can't read for some reason...");
    println!("{}", contents);
    let mut games:i32 = 0;
    let mut status:i32 = 0; // 0 for dont parse yet
    let mut counter:i32 = 0;
    for c in contents.chars()
    {
        if c <= '0' && c >= '9'
        {
            counter+=1;
            println!("{}", counter);
        }
        // see if first char for parsing is found
        if c == ':'
        {
            status = 1;
            counter = 0;
        }
        // see if second control char is found
        if c == ';'
        {
            status = 3;
            counter = 0;
        }
        if c == ' '
        {
            counter = 0;
        }
        if c == '\n'
        {
            println!("{games}");
            games += 1;
            status = 0;
        }
        if status == 1
        {
            counter += 1;
        }
    }
}