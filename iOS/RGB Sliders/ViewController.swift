//
//  ViewController.swift
//  first app
//
//  Created by Hunter Gray on 3/5/17.
//  Copyright © 2017 Hunter Gray. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    var colors: [Float] = [127.5,127.5,127.5]
    @IBOutlet weak var currentColors: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor(red: CGFloat(colors[0])/255.0, green: CGFloat(colors[1])/255.0, blue: CGFloat(colors[2])/255.0, alpha: 1)
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    
    @IBAction func redSlider(_ sender: UISlider) {
        colors[0] = sender.value
        currentColors.text = "\(Int(colors[0])), \(Int(colors[1])), \(Int(colors[2]))"
        self.view.backgroundColor = UIColor(red: CGFloat(colors[0])/255.0, green: CGFloat(colors[1])/255.0, blue: CGFloat(colors[2])/255.0, alpha: 1)
        
    }

    @IBAction func greenSlider(_ sender: UISlider) {
        colors[1] = sender.value
        currentColors.text = "\(Int(colors[0])), \(Int(colors[1])), \(Int(colors[2]))"
        self.view.backgroundColor = UIColor(red: CGFloat(colors[0])/255.0, green: CGFloat(colors[1])/255.0, blue: CGFloat(colors[2])/255.0, alpha: 1)
    }
    
    @IBAction func blueSlider(_ sender: UISlider) {
        colors[2] = sender.value
        currentColors.text = "\(Int(colors[0])), \(Int(colors[1])), \(Int(colors[2]))"
        self.view.backgroundColor = UIColor(red: CGFloat(colors[0])/255.0, green: CGFloat(colors[1])/255.0, blue: CGFloat(colors[2])/255.0, alpha: 1)
    }

    
    
    
}

