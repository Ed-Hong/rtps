from flask import Flask, jsonify, request
from flask_cors import CORS
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
CORS(app)

mock = [
  { 'id': 1, 'status': 1 },
  { 'id': 2, 'status': 0 },
  { 'id': 3, 'status': 0 },
  { 'id': 4, 'status': 0 },
  { 'id': 5, 'status': 0 },
  { 'id': 6, 'status': 0 },
  { 'id': 7, 'status': 0 },
  { 'id': 8, 'status': 0 },
  { 'id': 9, 'status': 0 },
  { 'id': 10, 'status': 0 }
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

# PUT endpoint for resetting spot statuses
@app.route('/spots', methods=['PUT'])
def reset_spots():
  for spot in mock:
    spot['status'] = 0
  return '', 204

# PUT endpoint for updating individual spot statuses
@app.route('/spots/<int:spotId>/<int:isFull>', methods=['PUT'])
def update_spot(spotId, isFull):
  for spot in mock:
    if spot['id'] == spotId:
      spot['status'] = isFull
      return jsonify(spot), 204
  return '', 404
