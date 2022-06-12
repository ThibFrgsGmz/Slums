module App {
    @ Component for blinking a tiva launchpad's onboard led
    passive component Blinker {
        @ Schedule input port
        sync input port schedIn: Svc.Sched
    }
}
