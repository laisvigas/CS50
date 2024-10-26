--[[
    ScoreState Class
    Author: Colton Ogden
    cogden@cs50.harvard.edu

    A simple state used to display the player's score before they
    transition back into the play state. Transitioned to from the
    PlayState when they collide with a Pipe.
]]

require 'Trophy'

ScoreState = Class{__includes = BaseState}

--[[
    When we enter the score state, we expect to receive the score
    from the play state so we know what to render to the State.
]]
function ScoreState:enter(params)
    self.score = params.score
    self.acornImage = Trophy:new("acorn.png", 100, 100)
    self.appleImage = Trophy:new("apple.png", 100, 100)
    self.cheeseImage = Trophy:new("cheese.png", 100, 100)
end

function ScoreState:update(dt)
    -- go back to play if enter is pressed
    if love.keyboard.wasPressed('enter') or love.keyboard.wasPressed('return') then
        gStateMachine:change('countdown')
    end
end

function ScoreState:render()
    love.graphics.setFont(flappyFont)
    love.graphics.printf('Oof! You lost!', 0, 64, VIRTUAL_WIDTH, 'center')

    love.graphics.setFont(mediumFont)
    love.graphics.printf('Score: ' .. tostring(self.score), 0, 100, VIRTUAL_WIDTH, 'center')

    local trophies = {
        {score = 10, message = 'You earned a cheese trophy \n I hope you are not lactose intolerant', image = self.cheeseImage, scale = self.cheeseImage.scale},
        {score = 3, message = 'You earned an apple trophy \n its a "fronk" one', image = self.appleImage, scale = self.appleImage.scale},
        {score = 1, message = 'You earned an acorn trophy for trying. \n Good luck next time... You will need it.', image = self.acornImage, scale = self.acornImage.scale},
    }

    local trophyEarned = false

    for _, trophy in ipairs(trophies) do
        if self.score >= trophy.score then
            trophyEarned = true
            love.graphics.setFont(mediumFont)
            local message = trophy.message
            local messageHeight = mediumFont:getHeight(message)
            love.graphics.printf(message, 0, 130, VIRTUAL_WIDTH, 'center')

            local imageX = (VIRTUAL_WIDTH - trophy.image.image:getWidth() * trophy.scale) / 2
            local imageY = (VIRTUAL_HEIGHT - trophy.image.image:getHeight() * trophy.scale) / 2 + messageHeight + 30

            trophy.image:draw(imageX, imageY, scale)
            break
        end
    end

    if not trophyEarned then
        love.graphics.printf('Come on, you can do better than that.', 0, 130, VIRTUAL_WIDTH, 'center')
    end

    love.graphics.printf('Press Enter to Play Again!', 0, 220, VIRTUAL_WIDTH, 'center')
end
