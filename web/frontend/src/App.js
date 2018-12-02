import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';
import {BrowserRouter, Route, NavLink, Link} from "react-router-dom";
import ParkingLot from './components/ParkingLot';
import ParkingLotUnderConstruction from './components/ParkingLotUnderConstruction';
import {View} from "express-react-views";
//import { Button } from 'react-native';
import {Button, ButtonToolbar} from 'react-bootstrap';


class App extends Component {
  // state = { WorkUncerConstructionButton : false }

  // toggleWorkUncerConstructionButton = () => {
  //   this.setState({ WorkUncerConstructionButton: !this.state.WorkUncerConstructionButton })
  // }
  
  state = {
    refresh: false
  };

  refreshHomePage = () => {
    console.log("REFRESHING HOME PAGE")
    if(!this.state.refresh) {
      this.setState({
        refresh: !this.state.refresh
      });
      //his.renderHomePage();
    } else {

    }
  }

  renderHomePage = () => {
    console.log("RENDERING HOME PAGE")
    console.log("this.state.refresh: " + this.state.refresh)

    if (!this.state.refresh && ( window.location.href === "http://localhost:3000/" || window.location.href === "http://localhost:3000") ){
    console.log("returning home page")  
    return(      <img style={{flex:1 , height: undefined , width: undefined, alignItems: 'cover'}} 
      src={"http://fatihtorun.net/wp-content/uploads/2018/05/utd-parking-seec-1-for-utd-map.png"} 
      alt={"utd parking map"}  />);
    } else {
      console.log("return  null")  
      return(null); 
    }
  }
  render() {

    return (
      <div className="App" style={{backgroundColor: "#d1e0e0"}}>

        {/* {this.renderHomePage()} */}
        {!this.state.refresh && <this.renderHomePage></this.renderHomePage>}
     
        <BrowserRouter>        
          <div>
          <Button 
            title="home"
            color="#841584"
            accessibilityLabel="home"            
          >
          <Link to="/">home</Link>     
          </Button>

          <Button class = "btn2"
            title="parkinglot2"
            color="#841584"
            accessibilityLabel="parkinglot under construction"
            onClick = {this.refreshHomePage}
          >
          <Link to="/components/ParkingLot2">parkingLot2</Link>   
          {/* {this.forceUpdate()}   */}
          </Button>
          
          <Button class = "btn1"
            title="parkinglot"
            color="#841584"
            accessibilityLabel="parkinglot"
          >
          <Link to="/components/ParkingLot">parkingLot</Link>     
          </Button>
            <switch>
              <Route path="/components/ParkingLot" component= {ParkingLot} exact />
              {/* {this.renderHomePage()} */}

              <Route path="/components/ParkingLot2" component= {ParkingLotUnderConstruction} /> 
              {/* {this.renderHomePage()} */}

              {/* <Route path="/" component= {App} />  */}
            </switch>
            
          </div>
        </BrowserRouter>

        
     
      </div>
    );
  }
}

export default App;
