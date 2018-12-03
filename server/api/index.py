from flask import Flask, jsonify, request
from datetime import datetime
import mysql.connector

###### Testing MySQL ######
# db = mysql.connector.connect(
#   host="localhost",
#   user="testuser",
#   passwd="testuserpassword123",
#   database="test"
# )

# cursor = db.cursor(buffered=True)
# cursor.execute("SELECT * FROM spots")

# for (id, isFull, lastUpdated) in cursor:
#   print("Spot {} isFull={} Last Updated on {:%d %b %Y}".format(
#     id, isFull, lastUpdated))
###### Testing MySQL ######



app = Flask(__name__)

mock = [
  { 'id': 1, 'isFull': True, 'lastUpdated': datetime.now()}
]

# GET API status
@app.route('/')
def api_status():
  return 'RTPS API is Alive \n'

# GET endpoint for spot statuses
@app.route('/spots')
def get_spots():
  return jsonify(mock)

# POST endpoint for creating new spots
@app.route('/spots', methods=['POST'])
def add_spot():
  mock.append(request.get_json())
  return '', 204

# PUT endpoint for resetting all spot statuses
@app.route('/spots?reset=true', methods=['PUT'])
def reset_spots():
  # loop through and reset all spot statuses to isEmpty
  # mock.append(request.get_json())
  return '', 204

# TODO PUT endpoint for updating spot statuses: route='/spots/{spotId}?isFull=true'