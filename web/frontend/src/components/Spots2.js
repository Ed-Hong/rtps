import React, { Component } from 'react';
import { Rect, Stage, Layer, Text } from 'react-konva';
import Konva from 'konva';
import { render } from 'react-dom';

class Spots2 extends Component {

    constructor(props) {
        super(props);

        this.state = {
            id: props.Id,
            color: (props.Status) ? 'green' : 'red',
            text: (props.Status) ? '' : 'X'
        };
    };

    render() {

        return (
            <>
            <Text x={440} y={100} text="camera 2"/>
            <Rect
                x={((this.state.id+1)%2)*60+60+350}
                y={Math.ceil((this.state.id)/2)*60 + 60}
                width={50}
                height={50}
                fill={"grey"}
                shadowBlur={5}
            />
           {/* <Text x={((this.state.id+1)%2)*60+60+350+2}
                y={Math.ceil((this.state.id)/2)*60 + 60-7}
                text={this.state.text}
                fontSize="67" /> */}
            </>
        );

    };
};

export default Spots2;