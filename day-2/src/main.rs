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
    let mut working:i32 = 0;
    let mut red:i32 = 0;
    let mut blue:i32 = 0;
    let mut green:i32 = 0;
    let mut yellow:i32 = 0;
    let char_vec: Vec<char> = contents.chars().collect();
    for c in contents.split_whitespace()
    {
        if  c.chars().nth(0).unwrap() >= '0' && c.chars().nth(0).unwrap() <= '9'
        {
            //println!("{}", c.parse::<i32>().unwrap());
            match c.parse::<i32>() {
                Ok(n) => {
                    working = n;
                    print!("{} ", working)
                },
                Err(e) => {
                    println!();
                    games += 1;
                    status = 1;
                    print!("Game {games}: ");
                },
            }
        }

        // see if second control char is found
        if c c.chars().nth(0).unwrap() == ';'
        {
            status = 3;
            counter = 0;
        }
    }
    println!();
}