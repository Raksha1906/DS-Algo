import axios from 'axios';
import chalk from 'chalk';
import ora from "ora";

const message = ora('')

export async function cli() {
  await getRandomQuote();
}

async function getRandomQuote() {
  message.start(`Retrieving random quote`);
  axios.get('https://api.quotable.io/random')
    .then(response => {
      message.succeed(`Successfully found random quote`);
      const quote = response.data.content;
      const author = response.data.author;
      console.log(chalk.white.bold(`\"${quote}\"`) + ' ~ ' +chalk.white.bold(`${author}`));
      process.exit();
    })
    .catch(error => {
      console.log(error);
    });
}
