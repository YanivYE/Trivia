import sqlite3
import requests
import json

API_URL = "https://opentdb.com/api.php?amount=10&difficulty=medium&type=multiple"  # Replace with your API URL


def get_json_content():
    # Make the HTTP GET request
    response = requests.get(API_URL)

    # Parse the JSON response
    data = json.loads(response.text)

    # Access and use the questions
    content = data["results"]
    return content


def insert_question(cursor, conn, question_data):
    # Execute an INSERT statement
    query = create_query(question_data)
    cursor.execute(query)

    # Commit the changes to the database
    conn.commit()


def create_query(data):
    query = "INSERT INTO questions (question, correct_answer, wrong_answer_1, wrong_answer_2, wrong_answer_3) VALUES ('" + \
            data['question'] + "','" + \
            data['correct_answer'] + "','" + \
            data['incorrect_answers'][0] + "','" + \
            data['incorrect_answers'][1] + "','" + \
            data['incorrect_answers'][2] + "')"
    return query


def main():
    # Establish a connection to an SQLite database
    conn = sqlite3.connect('MyDB.sqlite')
    cursor = conn.cursor()
    questions_data = get_json_content()
    # Iterate over the questions
    for question_data in questions_data:
        insert_question(cursor, conn, question_data)


if __name__ == "__main__":
    main()
